# ----------------------------------------------------------------------------
# SymForce - Copyright 2022, Skydio, Inc.
# This source code is under the Apache 2.0 license found in the LICENSE file.
# ----------------------------------------------------------------------------

import asyncio
import os
import re
import sys

from symforce import path_util
from symforce import python_util
from symforce import typing as T
from symforce.test_util import TestCase
from symforce.test_util import sympy_only


class SymforceRequirementsTest(TestCase):
    """
    Tests pip requirements
    """

    # Pass the --upgrade flag to piptools?
    _PIPTOOLS_UPGRADE = False

    @staticmethod
    def main(*args: T.Any, **kwargs: T.Any) -> None:
        """
        Call this to run all tests in scope.
        """
        if "--piptools_upgrade" in sys.argv:
            SymforceRequirementsTest._PIPTOOLS_UPGRADE = True
            sys.argv.remove("--piptools_upgrade")

        TestCase.main(*args, **kwargs)

    @sympy_only
    def test_requirements(self) -> None:
        output_dir = self.make_output_dir("sf_requirements_test_")

        version = sys.version_info.minor

        output_requirements_file = output_dir / f"dev_requirements_py3{version}.txt"
        symforce_requirements_file = path_util.symforce_root() / f"dev_requirements_py3{version}.txt"

        local_requirements_map = {
            "skymarshal @ file://localhost/{}/third_party/skymarshal": "file:./third_party/skymarshal",
            "symforce-sym @ file://localhost/{}/gen/python": "file:./gen/python",
        }

        # Copy the symforce requirements file into the temp directory
        # This is necessary so piptools has current versions of the packages already in the list
        if symforce_requirements_file.exists():
            requirements_contents = symforce_requirements_file.read_text()

            # Rewrite local paths to absolute paths
            # Pip isn't technically supposed to support relative paths, but it does and they're much
            # nicer for this use case
            # https://stackoverflow.com/a/64809439/2791611
            for key, value in local_requirements_map.items():
                requirements_contents = requirements_contents.replace(
                    value, key.format(path_util.symforce_root())
                )

            output_requirements_file.write_text(requirements_contents)

        maybe_piptools_upgrade = ["--upgrade"] if self._PIPTOOLS_UPGRADE else []

        asyncio.run(
            python_util.execute_subprocess(
                [
                    "uv",
                    "pip",
                    "compile",
                    "--all-extras",
                    f"--output-file={output_requirements_file}",
                    "--index-url=https://pypi.python.org/simple",
                    "pyproject.toml",
                ]
                + maybe_piptools_upgrade,
                cwd=path_util.symforce_root(),
                env=dict(
                    os.environ,
                    # Compile command to put in the header of dev_requirements.txt
                    CUSTOM_COMPILE_COMMAND="python test/symforce_requirements_test.py --update",
                ),
            )
        )

        # Reverse path rewrite back to relative paths
        requirements_contents = output_requirements_file.read_text()
        for key, value in local_requirements_map.items():
            requirements_contents = re.sub(key.format(".*"), value, requirements_contents)

        requirements_contents = requirements_contents.replace(str(output_dir) + "/", "")

        output_requirements_file.write_text(requirements_contents)

        self.compare_or_update_file(
            path_util.symforce_data_root() / f"dev_requirements_py3{version}.txt", output_requirements_file
        )


if __name__ == "__main__":
    SymforceRequirementsTest.main()
