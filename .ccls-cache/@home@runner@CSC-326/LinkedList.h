#pragma once

#include "Node.h"

namespace linkedlist {

class LinkedList {
public:
  LinkedList();

  const Node *head() const;
  const Node *tail() const;
  const int len() const;
  void append(int);
  void prepend(int);
  void insert(int);
  void remove(int);
  void reverse();
  void reverse_iter();

  int get_mid();
  int index_of(int);
  int getFrequencyof(int);
  void sort();
  void print();

  ~LinkedList();

private:
  Node *_head;
  Node *_tail;
  int _len = 0;
};

}