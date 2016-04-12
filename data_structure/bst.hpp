#ifndef DATA_STRUCTURE_BST_H_
#define DATA_STRUCTURE_BST_H_

#include <initializer_list>
#include <string>
#include <vector>

template<typename Key>
class BST {
 public:
  class BSTNode;

  // Destructor needs to cleanup resources.
  ~BST() {
    cleanup(root_);
    root_ = nullptr;
  }

  // One factory method that builds BST from a list. The list aranges
  // elems like it's a full binary tree, and use "#" to represent
  // missing nodes. For example, given {"5","3","7","#","1","#","8"}
  // represents a valid binary search tree.
  template<typename Convertor>
  static BST* build_from_list(std::initializer_list<std::string> l,
                              Convertor convert) {
    const std::string empty = "#";
    std::vector<BSTNode*> nodes;
    for (const std::string& elem : l) {
      nodes.push_back(
          elem == empty ? nullptr : new BSTNode(convert(elem)));
    }
    int n = nodes.size();
    for (int i = 0; i < n; i++) {
      if (nodes[i] == nullptr) continue;
      // Set parent pointer.
      if (i != 0) {
        nodes[i]->parent_ = nodes[(i-1)/2];
      }
      // Set left child pointer.
      if (2*i+1 < n) {
        nodes[i]->left_ = nodes[2*i+1];
      }
      // Set right child pointer.
      if (2*i+2 < n) {
        nodes[i]->right_ = nodes[2*i+2];
      }
    }
    return new BST(nodes.empty() ? nullptr : nodes[0]);
  }

  void insert(const Key& k) {
    this->root_ = insert_rec(this->root_, nullptr, k);
  }

  void remove(const Key& k) {
    BSTNode* cur = find_rec(this->root_, k);
    remove_rec(cur);
  }

  bool predecessor(const Key& k, Key& pre) {
    BSTNode* cur = find_rec(this->root_, k);
    if (cur == nullptr) return false;
    BSTNode* pre_node = predecessor(cur);
    if (pre_node != nullptr) pre = pre_node->key_;
    return pre_node != nullptr;
  }

  bool successor(const Key& k, Key& suc) {
    BSTNode* cur = find_rec(this->root_, k);
    if (cur == nullptr) return false;
    BSTNode* suc_node = successor(cur);
    if (suc_node != nullptr) suc = suc_node->key_;
    return suc_node != nullptr;
  }

  void inorder(std::vector<Key>& l) {
    inorder_rec(this->root_, l);
  }

  void preorder(std::vector<Key>& l) {
    preorder_rec(this->root_, l);
  }

  void postorder(std::vector<Key>& l) {
    postorder_rec(this->root_, l);
  }

 private:
  BSTNode* find_rec(BSTNode* cur, const Key& k) {
    if (cur == nullptr || cur->key_ == k) return cur;
    if (k < cur->key_) return find_rec(cur->left_, k);
    return find_rec(cur->right_, k);
  }

  BSTNode* insert_rec(BSTNode* cur, BSTNode* parent, const Key& k) {
    if (cur == nullptr) {
      cur = new BSTNode(k);
      cur->parent_ = parent;
      return cur;
    }
    if (k < cur->key_) {
      cur->left_ = insert_rec(cur->left_, cur, k);
    } else {
      cur->right_ = insert_rec(cur->right_, cur, k);
    }
    return cur;
  }

  void remove_rec(BSTNode* cur) {
    if (cur == nullptr) return;
    if (cur->left_ == nullptr && cur->right_ == nullptr) {
      remove_zero_child(cur);
      return;
    }
    if (cur->left_ == nullptr || cur->right_ == nullptr) {
      remove_one_child(cur);
      return;
    }
    BSTNode* p = cur->left_;
    while (p->right_ != nullptr) p = p->right_;
    std::swap(cur->key_, p->key_);
    remove_rec(p);
  }

  void remove_zero_child(BSTNode* cur) {
    if (cur->parent_ == nullptr) {
      this->root_ = nullptr;
    } else if (cur->parent_->left_ == cur) {
      cur->parent_->left_ = nullptr;
    } else {
      cur->parent_->right_ = nullptr;
    }
    delete cur;
  }

  void remove_one_child(BSTNode* cur) {
    BSTNode* c = cur->left_;
    if (c == nullptr) c = cur->right_;
    c->parent_ = cur->parent_;
    if (cur->parent_ == nullptr) {
      this->root_ = c;
    } else if (cur->parent_->left_ == cur) {
      cur->parent_->left_ = c;
    } else {
      cur->parent_->right_ = c;
    }
    delete cur;
  }

  BSTNode* predecessor(BSTNode* cur) {
    if (cur == nullptr) return nullptr;
    if (cur->left_ != nullptr) {
      BSTNode* p = cur->left_;
      while (p->right_ != nullptr) p = p->right_;
      return p;
    }
    while (cur->parent_ != nullptr && cur == cur->parent_->left_)
      cur = cur->parent_;
    return cur->parent_;
  }

  BSTNode* successor(BSTNode* cur) {
    if (cur == nullptr) return nullptr;
    if (cur->right_ != nullptr) {
      BSTNode* p = cur->right_;
      while (p->left_ != nullptr) p = p->left_;
      return p;
    }
    while (cur->parent_ != nullptr && cur == cur->parent_->right_)
      cur = cur->parent_;
    return cur->parent_;
  }

  void inorder_rec(BSTNode* p, std::vector<Key>& l) {
    if (p == nullptr) return;
    inorder_rec(p->left_, l);
    l.push_back(p->key_);
    inorder_rec(p->right_, l);
  }

  void preorder_rec(BSTNode* p, std::vector<Key>& l) {
    if (p == nullptr) return;
    l.push_back(p->key_);
    preorder_rec(p->left_, l);
    preorder_rec(p->right_, l);
  }

  void postorder_rec(BSTNode* p, std::vector<Key>& l) {
    if (p == nullptr) return;
    postorder_rec(p->left_, l);
    postorder_rec(p->right_, l);
    l.push_back(p->key_);
  }

  void cleanup(BSTNode* p) {
    if (p == nullptr) return;
    cleanup(p->left_);
    cleanup(p->right_);
    delete p;
  }

  // Disable constructors and assign operator.
  BST() = delete;
  BST(const BST&) = delete;
  BST& operator=(const BST&) = delete;

  // Make constructor private, and use factory method to initialize.
  BST(BSTNode* r) : root_(r) {}

  // Pointer to root node.
  BSTNode* root_;

 public:
  // Type for each node in BST.
  class BSTNode {
   public:
    BSTNode(const Key& k)
        : key_(k), left_(nullptr), right_(nullptr), parent_(nullptr) {
    }

    BSTNode(const Key& k, BSTNode* l, BSTNode* r, BSTNode* p)
        : key_(k), left_(l), right_(r), parent_(p) {
    }

    Key key_;
    BSTNode* left_;
    BSTNode* right_;
    BSTNode* parent_;
  };
};

#endif  // DATA_STRUCTURE_BST_H_
