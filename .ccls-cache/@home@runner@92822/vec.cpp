#include "vec.h"

Vec::Vec() : _size(0), _cap(0), arr(new int[1]) {}
Vec::Vec(int size) : _size(size), _cap(size), arr(new int[size]) {}
Vec::Vec(int size, int n) : _size(size), _cap(size), arr(new int[size]) {
  for (int i = 0; i < _size; i++)
    arr[i] = n;
}

int Vec::size() { return _size; }
int Vec::cap() { return _cap; }

void Vec::reserve(int cap) {
  if (cap > _cap) {
    _cap = cap;
    int *tmp = new int[_cap];
    for (int i = 0; i < _size; i++)
      tmp[i] = arr[i];
    delete[] arr;
    arr = tmp;
  }
}

void Vec::push(int n) {
  if (_size == _cap)
    reserve(_size * 2);
  arr[_size++] = n;
}

void Vec::insert(int idx, int n) {
  if (idx < 0 || idx > _size)
    throw "Error! Out of Bounds";
  if (_size == _cap)
    reserve(_size * 2);

  for (int i = _size++; i > idx; i--)
    arr[i] = arr[i - 1];
  arr[idx] = n;

  /*
  int* narr = new int[_size+1];
  for (int i = 0; i < _size+1; i++) {
          if (i < idx)
                  narr[i] = arr[i];
          else if (i == idx)
                  narr[i] = n;
          else narr[i] = arr[i - 1];
  }
  _size++;
  delete[] arr;
  arr = narr;
  */
}

int Vec::at(int idx) { return (idx > _size) ? throw "Err" : arr[idx]; }
int Vec::operator[](int idx) { return (idx > _size) ? throw "Err" : arr[idx]; }

Vec::~Vec() { delete[] arr; }