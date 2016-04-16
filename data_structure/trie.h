#ifndef DATA_STRUCTURE_TRIE_H_
#define DATA_STRUCTURE_TRIE_H_

#include <memory>
#include <string>
#include <vector>

//
// A trie is a 256-ary tree that represents a set of strings.
//
class Trie {
 public:
  Trie();
  ~Trie() = default;

  // Disable copy constructor and assignment operator.
  Trie(const Trie&) = delete;
  Trie& operator=(const Trie&) = delete;

  // (1) If "word" is not in Trie, insert string "word" into Trie, and
  // return true.
  // (2) If "word" is already in Trie, return false.
  bool Insert(const char* word);

  // If "word" is in Trie, return true. Otherwise return false.
  bool Contain(const char* word) const;

  // Remove "word" from this Trie. If "word" was in this Trie, return
  // true. Otherwise return false.
  bool Delete(const char* word);

  // Return the number of "words" in this Trie.
  int Size() const;

  // Return true if this Trie doesn't have any Word.
  bool IsEmpty() const;

  // Return the number of "words" in this Trie that start with "prefix".
  int WordCountWithPrefix(const char* prefix) const;

  // Return the "word" in this Trie that is the longest prefix of
  // "str".
  std::string LongestPrefix(const char* str) const;

 private:
  struct Node {
    Node();
    ~Node() = default;

    // Set to true if path from root to this node represents a word.
    bool is_word_;
    // Number of words rooted at this node.
    int count_;
    // Pointers to children nodes.
    std::vector<std::unique_ptr<Node>> next_;
  };

  std::unique_ptr<Node> root_;

  // Helper functions.
  bool InsertRecursively(Node* cur, const char* word);
  bool ContainRecursively(Node* cur, const char* word) const;
  bool DeleteRecursively(Node* cur, const char* word);
  int WordCountWithPrefixRecursively(Node* cur, const char* prefix) const;
  const char* LongestPrefix(Node* cur, const char* str) const;
};

#endif  // DATA_STRUCTURE_TRIE_H_
