#pragma once

// Node = i
// left (i) = 2i
// right (i) = 2i+1
// parent (i) = i/2
namespace heap {
class MaxHeap {
public:
  MaxHeap() : cap_(1), size_(0), arr_(new int[0]) {}
  MaxHeap(int *arr, int size) : cap_(size), size_(size), arr_(new int[size]) {
    for (int i = 0; i < size; i++)
      arr_[i] = arr[i];
    heapify();
  }

  void heapify() {
    for (int i = size_ - 1; i >= 0; --i)
      siftUp(i);
  }

  void swap(int &x, int &y) {
    int tmp = y;
    y = x;
    x = tmp;
  }

  void siftUp(int i) {
    if (arr_[parent(i)] > arr_[i])
      return;
    swap(arr_[parent(i)], arr_[i]);
    siftUp(parent(i));
  }

  // void insert(int val) {
  // }

  // void remove(int i) {
  // }

private:
  int *arr_, size_, cap_;
  int left(int i) { return i * 2; }
  int right(int i) { return i * 2 + 1; }
  int parent(int i) { return i / 2; }
};
} // namespace heap