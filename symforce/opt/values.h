#pragma once

#include <unordered_map>

#include <lcmtypes/sym/values_t.hpp>
#include <lcmtypes/sym/valuesf_t.hpp>

#include "./key.h"
#include "./type_ops.h"

namespace sym {

/**
 * Efficient polymorphic data structure to store named types with a dict-like interface and
 * support efficient repeated operations using a key index. Supports on-manifold optimization.
 *
 * Compatible types are given by the type_t enum. All types implement the StorageOps and
 * LieGroupOps concepts, which are the core operating mechanisms in this class.
 */
template <typename Scalar>
class Values {
 public:
  using MapType = std::unordered_map<Key, index_entry_t>;
  using ArrayType = std::vector<Scalar>;

  // Expose the correct LCM type (values_t or valuesf_t)
  template <typename _S, bool _D = true>
  struct LcmTypeHelper {};
  using LcmType = typename LcmTypeHelper<Scalar>::Type;

  /**
   * Default construct as empty.
   */
  Values();

  /**
   * Construct from serialized form.
   */
  explicit Values(const LcmType& msg);

  /**
   * Return whether the key exists.
   */
  bool Has(const Key& key) const;

  /**
   * Retrieve a value by key.
   */
  template <typename T>
  T At(const Key& key) const;

  /**
   * Add or update a value by key. Returns true if added, false if updated.
   */
  template <typename T>
  bool Set(const Key& key, const T& value);

  /**
   * Update or add keys to this Values base on other Values of different structure.
   * index MUST be valid for other.
   *
   * NOTE(alvin): it is less efficient than the Update methods below if index objects are
   *              created and cached. This method performs map lookup for each key of the index
   */
  void UpdateOrSet(const index_t& index, const Values<Scalar>& other);

  /**
   * Number of keys.
   */
  int32_t NumEntries() const;

  /**
   * Get all keys.
   *
   * Args:
   *   sort_by_offset: Sorts by storage order to make iteration safer and more memory efficient
   *
   * NOTE(hayk): If we changed key storage to a sorted vector this could automatically be maintained
   * and it would be more embedded friendly, but At(key) would become O(N) for linear search.
   */
  std::vector<Key> Keys(const bool sort_by_offset = true) const;

  /**
   * Expose map type to allow iteration.
   */
  const MapType& Items() const;

  /**
   * Raw data buffer.
   */
  const ArrayType& Data() const;

  /**
   * Remove the given key. Only removes the index entry, does not change the data array.
   * Returns true if removed, false if already not present.
   *
   * Call Cleanup() to re-pack the data array.
   */
  bool Remove(const Key& key);

  /**
   * Remove all keys and empty out the storage.
   */
  void RemoveAll();

  /**
   * Repack the data array to get rid of empty space from removed keys. If regularly removing
   * keys, it's up to the user to call this appropriately to avoid storage growth. Returns the
   * number of Scalar elements cleaned up from the data array.
   *
   * It will INVALIDATE all indices, offset increments, and pointers.
   * Re-create an index with CreateIndex().
   */
  size_t Cleanup();

  /**
   * Create an index from the given ordered subset of keys. This object can then be used
   * for repeated efficient operations on that subset of keys.
   *
   * If you want an index of all the keys, call `values.CreateIndex(values.Keys())`.
   *
   * An index will be INVALIDATED if the following happens:
   *  1) Remove() is called with a contained key, or RemoveAll() is called
   *  2) Cleanup() is called to re-pack the data array
   *
   * NOTE(hayk): We could also add a simple UpdateIndex(&index) method, since the offset is the
   * only thing that needs to get updated after repacking.
   */
  index_t CreateIndex(const std::vector<Key>& keys) const;

  /**
   * Retrieve a value by index entry. This avoids a map lookup compared to At(key).
   */
  template <typename T>
  T At(const index_entry_t& entry) const;

  /**
   * Update a value by index entry with no map lookup (compared to Set(key)).
   * This does NOT add new values and assumes the key exists already.
   */
  template <typename T>
  void Set(const index_entry_t& key, const T& value);

  /**
   * Efficiently update the keys given by this index from other into this. This purely copies
   * slices of the data arrays, the index MUST be valid for both objects!
   */
  void Update(const index_t& index, const Values<Scalar>& other);

  /**
   * Efficiently update the keys from a different structured Values, given by
   * this index and other index. This pureply copies slices of the data arrays.
   * index_this MUST be valid for this object; index_other MUST be valid for other object.
   */
  void Update(const index_t& index_this, const index_t& index_other, const Values<Scalar>& other);

  /**
   * Perform a retraction from an update vector.
   *
   * Args:
   *   index: Ordered list of keys in the delta vector
   *   delta: Pointer to update vector - MUST be the size of index.tangent_dim!
   *   epsilon: Small constant to avoid singularities (do not use zero)
   */
  void Retract(const index_t& index, const Scalar* delta, const Scalar epsilon);

  /**
   * Serialize to LCM.
   */
  void FillLcmType(LcmType* msg) const;
  LcmType GetLcmType() const;

 protected:
  MapType map_;
  ArrayType data_;
};

// Shorthand instantiations
using Valuesd = Values<double>;
using Valuesf = Values<float>;

}  // namespace sym

/**
 * Prints entries with their keys, data slices, and values, like:
 *
 *   Valuesd entries=4 array=8 storage_dim=7 tangent_dim=6
 *     R_1 [0:4] --> <Rot3d [0.563679, 0.0939464, 0, 0.820634]>
 *     f_1 [5:6] --> 4.2
 *     f_2 [6:7] --> 4.3
 *     d_1 [7:8] --> 4.3
 *   >
 */
template <typename Scalar>
std::ostream& operator<<(std::ostream& os, const sym::Values<Scalar>& v);

// Template method implementations
#include "./values.tcc"