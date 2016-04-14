#ifndef DATA_STRUCTURE_TRIE_H_
#define DATA_STRUCTURE_TRIE_H_

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

//
// A trie is a 256-ary tree that represents a set of strings.
//

template<typename T>
struct Node final {
  static const int kSize;

  Node(char ch, const T& value);
  ~Node();

  char ch_;
  T value_;
  std::vector<std::unique_ptr<Node>> next_;
};

template<typename T, T NULL_VALUE>
class Trie final {
 public:
  typedef T value_type;

  static const char kNullChar;
  static const T kNullValue;

  Trie();
  ~Trie();

  Trie(const Trie&) = delete;
  Trie& operator=(const Trie&) = delete;

  // (1) If "key" is not in Trie, insert string "key" into Trie,
  // associate "value" with it, and return true.
  //
  // (2) If "key" is already in Trie, overwrite its value to "value",
  // and return false.
  bool Insert(const char* key, const T& value);

  // If "key" is in Trie, return its associated value. Otherwise,
  // return kNullValue.
  const T& Get(const char* key) const;

  // If "key" is in Trie, return true. Otherwise return false.
  bool Contains(const char* key) const;

 private:
  std::unique_ptr<Node<T>> root_;

  bool InsertRecursively(Node<T>* cur, const char* key, const T& value);
};

template<typename T>
const int Node<T>::kSize = 256;

template<typename T>
Node<T>::Node(char ch, const T& value)
    : ch_(ch), value_(value), next_(kSize) {
}

template<typename T>
Node<T>::~Node() {
}

template<typename T, T NULL_VALUE>
const char Trie<T, NULL_VALUE>::kNullChar = '\0';

template<typename T, T NULL_VALUE>
const T Trie<T, NULL_VALUE>::kNullValue = NULL_VALUE;

template<typename T, T NULL_VALUE>
Trie<T, NULL_VALUE>::Trie()
    : root_(new Node<T>(kNullChar, kNullValue)) {
}

template<typename T, T NULL_VALUE>
Trie<T, NULL_VALUE>::~Trie() {
}

template<typename T, T NULL_VALUE>
bool Trie<T, NULL_VALUE>::Insert(const char* key, const T& value) {
  assert(*key != kNullChar);
  return InsertRecursively(root_.get(), key, value);
}

template<typename T, T NULL_VALUE>
bool Trie<T, NULL_VALUE>::InsertRecursively(
    Node<T>* cur, const char* key, const T& value) {
  assert(cur != nullptr);
  // Base case.
  if (*key == kNullChar) {
    cur->value_ = value;
    return false;
  }
  bool created_node = false;
  int i = static_cast<int>(*key);
  if (cur->next_[i] == nullptr) {
    cur->next_[i].reset(new Node<T>(*key, kNullValue));
    created_node = true;
  }
  return InsertRecursively(cur->next_[i].get(), key + 1, value) ||
      created_node;
}

#endif  // DATA_STRUCTURE_TRIE_H_
