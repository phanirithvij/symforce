// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     js_templates/function/FUNCTION.js.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

function foo(a, b, c, epsilon)
{
    // Total ops: 18

    // Input arrays

    // Intermediate terms (0)

    // Output terms
    let _one = Array(3);
    _one[0] = a + c[0];
    _one[1] = Math.pow(Math.sin(b), a);
    _one[2] = Math.pow(b, 2)/(a - b - c[1] - epsilon);

    let _two = Array(2);
    _two[0] = -Math.atan2(b, a);
    _two[1] = (a + b)/Math.sqrt(Math.pow(c[0], 2) + Math.pow(c[1], 2) + epsilon);

    return _one,  _two
}

console.log(foo(3, 4, [1, 2], 1e-6))
console.log(foo(0, 0, [0, 0], 1e-6))
