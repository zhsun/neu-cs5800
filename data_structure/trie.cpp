#include <cassert>
#include <iostream>

#include "data_structure/trie.h"

using std::string;
using std::vector;

const int kSize = 256;
const char kNullChar = '\0';

Trie::Node::Node() : is_word_(false), count_(0), next_(kSize) {
}

Trie::Trie() : root_(new Trie::Node) {
}

bool Trie::Insert(const char* word) {
  assert(*word != kNullChar);
  return InsertRecursively(root_.get(), word);
}

bool Trie::InsertRecursively(Trie::Node* cur, const char* word) {
  assert(cur != nullptr);
  // Base case.
  if (*word == kNullChar) {
    if (cur->is_word_) {
      // The given "word" was already in Trie, return false.
      return false;
    }
    cur->is_word_ = true;
    ++cur->count_;
    return true;
  }
  // Recursive case.
  int i = static_cast<int>(*word);
  if (cur->next_[i] == nullptr) {
    cur->next_[i].reset(new Node);
  }
  if (InsertRecursively(cur->next_[i].get(), word + 1)) {
    ++cur->count_;
    return true;
  }
  return false;
}

bool Trie::Contain(const char* word) const {
  assert(*word != kNullChar);
  return ContainRecursively(root_.get(), word);
}

bool Trie::ContainRecursively(Trie::Node* cur, const char* word) const {
  assert(cur != nullptr);
  if (*word == kNullChar) {
    return cur->is_word_;
  }
  int i = static_cast<int>(*word);
  if (cur->next_[i] == nullptr) {
    return false;
  }
  return ContainRecursively(cur->next_[i].get(), word + 1);
}

bool Trie::Delete(const char* word) {
  assert(*word != kNullChar);
  return DeleteRecursively(root_.get(), word);
}

bool Trie::DeleteRecursively(Node* cur, const char* word) {
  assert(cur != nullptr);
  // Base case.
  if (*word == kNullChar) {
    if (cur->is_word_) {
      cur->is_word_ = false;
      --cur->count_;
      return true;
    }
    return false;
  }
  // Recursive case.
  int i = static_cast<int>(*word);
  if (cur->next_[i] == nullptr) {
    return false;
  }
  if (DeleteRecursively(cur->next_[i].get(), word + 1)) {
    --cur->count_;
    if (cur->next_[i]->count_ == 0) {
      cur->next_[i] = std::unique_ptr<Trie::Node>(nullptr);
    }
    return true;
  }
  return false;
}

int Trie::Size() const {
  return root_->count_;
}

bool Trie::IsEmpty() const {
  return Size() == 0;
}

int Trie::WordCountWithPrefix(const char* prefix) const {
  assert(*prefix != kNullChar);
  return WordCountWithPrefixRecursively(root_.get(), prefix);
}

int Trie::WordCountWithPrefixRecursively(Node* cur, const char* prefix) const {
  assert(cur != nullptr);
  // Base case.
  if (*prefix == kNullChar) {
    return cur->count_;
  }
  int i = static_cast<int>(*prefix);
  if (cur->next_[i] == nullptr) {
    return 0;
  }
  return WordCountWithPrefixRecursively(cur->next_[i].get(), prefix + 1);
}

vector<string> Trie::WordsWithPrefix(const char* prefix) const {
  // TODO
  return vector<string>();
}

string Trie::LongestPrefix(const char* str) const {
  // TODO
  return string();
}
