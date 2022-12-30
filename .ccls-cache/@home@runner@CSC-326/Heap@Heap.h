#pragma once

// MAX HEAP
// Node = i
// left (i) = 2i + 1
// right (i) = 2i + 2
// parent (i) = (i-1)/2
namespace heap {
class Heap {
public:
  Heap() : cap_(1), size_(0), arr_(new int[0]) {}
  Heap(int *arr, int size) : cap_(size), size_(size), arr_(new int[size]) {
    for (int i = 0; i < size; ++i)
      arr_[i] = arr[i];
    heapify(arr_, size);
  }

  const int size() const { return size_; }
  const int *arr() const { return arr_; } // Temp

  bool empty() const { return !size_; }

  int max() { return arr_[0]; }

  void heapify(int *arr, int size) {
    for (int i = 0; i < size; ++i)
      siftUp(arr, i);
  }

  void insert(int val) {
    if (size_ == cap_)
      reserve(cap_ * 2);
    arr_[size_] = val;
    siftUp(arr_, size_);
    ++size_;
  }

  int extractMax() {
    int fin = arr_[0];
    swap(arr_[0], arr_[--size_]);
    siftDown(arr_);
    return fin;
  }

  void removeMax() {
    arr_[0] = arr_[--size_];
    siftDown(arr_);
  }

  void remove(int i) {
    swap(arr_[i], arr_[--size_]);
    siftDown(arr_, i);
  }

private:
  int *arr_, size_, cap_;
  inline int left(int i) { return i * 2 + 1; }
  inline int right(int i) { return i * 2 + 2; }
  inline int parent(int i) { return (i - 1) / 2; }

  void siftUp(int *arr, int i) {
    if (i == 0 || arr[parent(i)] > arr[i])
      return;
    swap(arr[parent(i)], arr[i]);
    siftUp(arr, parent(i));
  }

  void siftDown(int *arr) { siftDown(arr, 0); }

  void siftDown(int *arr, int i) {
    if (i > size_ && left(i) > size_ && right(i) > size_)
      return;
    if (arr[left(i)] > arr[i] && arr[right(i)] < arr[left(i)]) {
      swap(arr[left(i)], arr[i]);
      siftDown(arr, left(i));
    } else if (arr[right(i)] > arr[i]) {
      swap(arr[right(i)], arr[i]);
      siftDown(arr, right(i));
    }
  }

  void swap(int &x, int &y) {
    int tmp = y;
    y = x;
    x = tmp;
  }

  void reserve(int cap) {
    if (cap > cap_) {
      cap_ = cap;
      int *tmp = new int[cap_];
      for (int i = 0; i < size_; i++)
        tmp[i] = arr_[i];
      delete[] arr_;
      arr_ = tmp;
    }
  }
};
} // namespace heap
