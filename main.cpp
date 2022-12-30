#include <iostream>

#include "Heap/Heap.h"
#include "LinkedList/LinkedList.h"
#include "Queue/Queue.h"
#include "Stack/Stack.h"
#include "Tree/Tree.h"
#include "Vec/Vec.h"

using std::cout;
using std::endl;
using std::string;

using heap::Heap;
using linkedlist::LinkedList;
using queue::Queue;
using stack::Stack;
using tree::Tree;
using vec::Vec;

// Print the vector with size and cappacity
template <typename T> void print(const Vec<T> &vec) {
  for (int i = 0; i < vec.size(); ++i)
    cout << vec.at(i) << " ";
  cout << "| Size: " << vec.size() << " Capacity: " << vec.cap() << endl;
}

// Print the heap with size
void print(const Heap &heap) {
  for (int i = 0; i < heap.size(); ++i)
    cout << heap.arr()[i] << " ";
  cout << "| Size: " << heap.size() << endl;
}

// General print function for combining a string and a value
template <typename T> void print(const string str, const T val) {
  cout << str << " " << val << endl;
}

int main() {
  // VECTOR Testing
  Vec<string> vec(3, "Hello");
  vec.pop();
  vec.push("Hey");
  vec.insert(0, "Hey");
  print(vec);
  cout << "----------------------------------" << endl;

  Vec<int> ve(5);
  for (int i = 0; i < ve.size(); ++i)
    ve[i] = i;
  print(ve);

  print("Index of 1:", ve.index_of(1));
  ve.remove(1);
  print("Index of 1:", ve.index_of(1));

  ve.push(5);
  ve.push(6);
  print(ve);

  auto ves = ve;
  ves.push(1);
  ves.push(9);
  ves.push(7);
  ves.sort();
  print(ves);
  cout << "----------------------------------" << endl;

  auto v = Vec<int>(6, 3) + ve * 2 - 1;
  v.reserve(20);
  print(v);
  cout << "----------------------------------" << endl;

  int dot = ve * v;
  print("Dot product:", dot);
  cout << "----------------------------------" << endl;

  try {
    Vec<int> v = Vec<int>(4, 3) + ve * 3;
  } catch (char const *e) {
    cout << e << endl;
    cout << "----------------------------------" << endl;
  }

  try {
    v.push(2);
    int dot = ve * v;
  } catch (char const *e) {
    cout << e << endl;
    cout << "----------------------------------" << endl;
  }

  try {
    v.insert(10, 20);
  } catch (char const *e) {
    cout << e << endl;
    cout << "__________________________________\nLINKEDLIST" << endl;
  }

  // LINKED LIST Testing
  LinkedList<int> l;

  for (int i = 0; i < 10; ++i)
    if (i != 2)
      l.append(i);
  l.print();
  cout << "----------------------------------" << endl;

  l.insert(2);
  print("Length:", l.len());
  print("Middle:", l.get_mid());
  print("Index Of 5:", l.index_of(5));
  print("Frequency Of 5:", l.getFrequencyof(5));
  print("Last K With 5:", l.last_k(5));

  cout << "----------------------------------" << endl;
  l.insert(2);
  l.insert(50);
  l.remove(3);
  l.print();

  l.reverse();
  l.print();
  l.sort();
  l.print();
  l.reverse_iter();
  l.print();

  l.append(3);
  l.prepend(3);
  l.print();
  cout << "__________________________________\nSTACK" << endl;

  // STACK Testing
  Stack<int> stackInt;
  stackInt.push(0);
  cout << stackInt.peek() << endl;
  stackInt.push(1);
  cout << stackInt.peek() << endl;
  stackInt.pop();
  cout << stackInt.peek() << endl;
  stackInt.push(2);
  cout << stackInt.peek() << endl;

  cout << "__________________________________\nQUEUE" << endl;

  // QUEUE Testing
  Queue<int> queueInt;
  queueInt.enqueue(5);
  cout << queueInt.peek() << endl;
  queueInt.enqueue(3);
  cout << queueInt.peek() << endl;
  queueInt.dequeue();
  cout << queueInt.peek() << endl;

  cout << "__________________________________\nTREE" << endl;

  // TREE Testing
  Tree<int> tree(5, 5);
  tree.insert(8);
  tree.insert(9);
  tree.insert(4);
  tree.insert(2);
  tree.traversalPreOrder();
  tree.traversalInOrder();
  tree.traversalPostOrder();

  // 0 if null, otherwise value inside
  auto null_check = [](tree::Node<int> *a) -> int { return (a) ? a->val : 0; };
  print("Value of Key 2:", tree.search(2)->val);
  print("For Key 2 using Recursive Search:", tree.searchRecursive(2)->val);
  print("For Non-Existant Key (null shown as 0):", null_check(tree.search(6)));
  print("Successor of Root:", tree.succ(5)->val);
  print("Successor of 8:", tree.succ(8)->val);
  print("Predecessor of Root:", tree.pred(5)->val);
  print("Predecessor of 4:", tree.pred(4)->val);

  tree.traversalInOrder();
  tree.remove(4);
  tree.traversalInOrder();
  tree.remove(8);
  tree.traversalInOrder();
  tree.remove(5);
  tree.traversalInOrder();

  cout << "__________________________________\nHEAP" << endl;

  // HEAP Testing
  int heap_arr[] = {5, 3, 7, 9, 12, 4, 2};
  for (int i = 0; i < 7; ++i)
    cout << heap_arr[i] << " ";
  cout << endl;
  Heap heap(heap_arr, 7);
  print(heap);
  heap.insert(16);
  heap.insert(1);
  print(heap);
  heap.removeMax();
  print(heap);

  return 0;
}