#include <memory>

#include "gmock/gmock.h"
#include "bst.hpp"

#include <algorithm>
#include <iterator>

using namespace std;
using namespace testing;

TEST(BSTTest, BuildFromList) {
  unique_ptr<BST<int>> tree(BST<int>::build_from_list(
      {"5","3","7","#","4","#","8"},
      [](const string& a) { return stoi(a); }));
  vector<int> in;
  tree->inorder(in);
  EXPECT_THAT(in, ElementsAre(3,4,5,7,8));
  vector<int> pre;
  tree->preorder(pre);
  EXPECT_THAT(pre, ElementsAre(5,3,4,7,8));
  vector<int> post;
  tree->postorder(post);
  EXPECT_THAT(post, ElementsAre(4,3,8,7,5));
}

TEST(BSTTest, Insert) {
  unique_ptr<BST<int>> tree(BST<int>::build_from_list(
      {"5","3","7","#","4","#","8"},
      [](const string& a) { return stoi(a); }));
  tree->insert(2);
  tree->insert(6);
  tree->insert(10);
  vector<int> in;
  tree->inorder(in);
  EXPECT_THAT(in, ElementsAre(2,3,4,5,6,7,8,10));
}

TEST(BSTTest, Predecessor) {
  unique_ptr<BST<int>> tree(BST<int>::build_from_list(
      {"5","3","8","#","4","7","#"},
      [](const string& a) { return stoi(a); }));
  int pre;
  EXPECT_THAT(tree->predecessor(10, pre), Eq(false));
  EXPECT_THAT(tree->predecessor(5, pre), Eq(true));
  EXPECT_THAT(pre, Eq(4));
  EXPECT_THAT(tree->predecessor(3, pre), Eq(false));
  EXPECT_THAT(tree->predecessor(7, pre), Eq(true));
  EXPECT_THAT(pre, Eq(5));
  EXPECT_THAT(tree->predecessor(4, pre), Eq(true));
  EXPECT_THAT(pre, Eq(3));
}

TEST(BSTTest, Successor) {
  unique_ptr<BST<int>> tree(BST<int>::build_from_list(
      {"5","3","8","#","4","7","#"},
      [](const string& a) { return stoi(a); }));
  int suc;
  EXPECT_THAT(tree->successor(10, suc), Eq(false));
  EXPECT_THAT(tree->successor(5, suc), Eq(true));
  EXPECT_THAT(suc, Eq(7));
  EXPECT_THAT(tree->successor(8, suc), Eq(false));
  EXPECT_THAT(tree->successor(4, suc), Eq(true));
  EXPECT_THAT(suc, Eq(5));
  EXPECT_THAT(tree->successor(7, suc), Eq(true));
  EXPECT_THAT(suc, Eq(8));
}

TEST(BSTTest, Remove) {
  unique_ptr<BST<int>> tree(BST<int>::build_from_list(
      {"5","3","8","#","4","7","#"},
      [](const string& a) { return stoi(a); }));
  vector<int> in;
  tree->remove(5);
  tree->inorder(in);
  EXPECT_THAT(in, ElementsAre(3,4,7,8));
  in.clear();
  tree->remove(3);
  tree->inorder(in);
  EXPECT_THAT(in, ElementsAre(4,7,8));
  in.clear();
  tree->remove(7);
  tree->inorder(in);
  EXPECT_THAT(in, ElementsAre(4,8));
  in.clear();
  tree->remove(4);
  tree->inorder(in);
  EXPECT_THAT(in, ElementsAre(8));
  in.clear();
  tree->remove(8);
  tree->inorder(in);
  EXPECT_THAT(in.empty(), Eq(true));
}
