#include "Node.h"

#include <iostream>

namespace tree {

template <typename T> class Tree {
public:
  Tree() : root_(nullptr) {}
  Tree(int val) : root_(new Node<int>(val, val)) {}
  Tree(int key, T val) : root_(new Node<T>(key, val)) {}

  Node<T> *root() { return root_; }

  void insert(int val) { insert(val, val); }

  void insert(int key, T val) {
    Node<T> *par;
    Node<T> *cur = root_;
    Node<T> *node = new Node<T>(key, val);

    if (!cur) {
      cur = node;
      return;
    }

    while (cur) {
      par = cur;
      cur = (key < cur->key) ? cur->l : cur->r;
    }

    if (key < par->key) {
      par->l = node;
      node->p = par;
    } else {
      par->r = node;
      node->p = par;
    }
  }

  void remove(int key) { remove(search(key)); }

  void remove(Node<T> *node) {
    if (!node->l)
      transplant_(node, node->r);
    else if (!node->r)
      transplant_(node, node->l);
    else {
      auto helper = min(node->r);
      if (helper->p != node) {
        transplant_(helper, helper->r);
        helper->r = node->r;
        helper->r->p = helper;
      }
      transplant_(node, helper);
      helper->l = node->l;
      helper->l->p = helper;
    }
  }

  Node<T> *search(int key) const {
    Node<T> *cur = root_;

    while (cur)
      if (key == cur->key)
        return cur;
      else
        cur = (key < cur->key) ? cur->l : cur->r;

    return nullptr;
  }

  Node<T> *searchRecursive(int key) const {
    return searchRecursive(root_, key);
  }

  Node<T> *searchRecursive(Node<T> *cur, int key) const {
    return (cur) 
      ? (key == cur->key)  
      ? cur
      : (key < cur->key) 
      ? searchRecursive(cur->l, key)
      : searchRecursive(cur->r, key)
      : nullptr;
  }

  Node<T> *min() const { return min(root_); };
  Node<T> *min(Node<T> *cur) const {
    if (!cur)
      return nullptr;
    while (cur->l)
      cur = cur->l;
    return cur;
  }

  Node<T> *max() const { return max(root_); };
  Node<T> *max(Node<T> *cur) const {
    if (!cur)
      return nullptr;
    while (cur->r)
      cur = cur->r;
    return cur;
  }

  Node<T> *succ(int key) const { return succ(search(key)); }
  Node<T> *succ(Node<T> *cur) const {
    if (cur->r)
      return min(cur->r);

    Node<T> *helper = cur->p;

    while (helper && cur == helper->r) {
      cur = helper;
      helper = helper->p;
    }

    return helper;
  }

  Node<T> *pred(int key) const { return pred(search(key)); }
  Node<T> *pred(Node<T> *cur) const {
    if (cur->l)
      return max(cur->l);

    Node<T> *helper = cur->p;

    while (helper && cur == helper->l) {
      cur = helper;
      helper = helper->p;
    }

    return helper;
  }

  void traversalPreOrder() {
    traversalPreOrder(root_);
    std::cout << std::endl;
  }
  void traversalPreOrder(Node<T> *node) {
    if (node) {
      std::cout << node->val << " ";
      traversalPreOrder(node->l);
      traversalPreOrder(node->r);
    }
  }

  void traversalInOrder() {
    traversalInOrder(root_);
    std::cout << std::endl;
  }
  void traversalInOrder(Node<T> *node) {
    if (node) {
      traversalPreOrder(node->l);
      std::cout << node->val << " ";
      traversalPreOrder(node->r);
    }
  }

  void traversalPostOrder() {
    traversalPostOrder(root_);
    std::cout << std::endl;
  }
  void traversalPostOrder(Node<T> *node) {
    if (node) {
      traversalPreOrder(node->l);
      traversalPreOrder(node->r);
      std::cout << node->val << " ";
    }
  }

private:
  Node<T> *root_;

  void transplant_(Node<T> *cur, Node<T> *repl) {
    if (!cur->p)
      root_ = repl;
    else if (cur == cur->p->l)
      cur->p->l = repl;
    else
      cur->p->r = repl;
    if (repl)
      repl->p = cur->p;
  }
};
} // namespace tree