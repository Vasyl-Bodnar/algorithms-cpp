#include "Vec.h"

Vec::Vec() : _size(1), _cap(1), arr(new int[1]) { arr[0] = 0; }
Vec::Vec(int size) : _size(size), _cap(size), arr(new int[size]) {}
Vec::Vec(int size, int n) : _size(size), _cap(size), arr(new int[size]) {
  for (int i = 0; i < _size; i++)
    arr[i] = n;
}

const int Vec::size() const { return _size; }
const int Vec::cap() const { return _cap; }

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

void Vec::pop() { _size--; }

void Vec::insert(int idx, int n) {
  if (idx < 0 || idx > _size)
    throw "Error! Out of Bounds";
  if (_size == _cap)
    reserve(_size * 2);

  for (int i = _size++; i > idx; i--)
    arr[i] = arr[i - 1];
  arr[idx] = n;
}

void Vec::remove(int idx) {
  if (idx < 0 || idx > _size--)
    throw "Error! Out of Bounds";

  for (int i = idx; i < _size; i++)
    arr[i] = arr[i + 1];
}

const int Vec::at(int idx) const {
  return (idx > _size) ? throw "Err" : arr[idx];
}
int Vec::operator[](int idx) { return (idx > _size) ? throw "Err" : arr[idx]; }

Vec operator+(const Vec &a, int other) {
  Vec vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = (a.at(i) + other);
  return vec;
}
Vec operator*(const Vec &a, int other) {
  Vec vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = (a.at(i) * other);
  return vec;
}
Vec operator+(const Vec &a, const Vec &b) {
  if (a.size() != b.size())
    throw "Sizes do not match";
  Vec vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = a.at(i) + b.at(i);
  return vec;
}
Vec operator*(const Vec &a, const Vec &b) {
  if (a.size() != b.size())
    throw "Sizes do not match";
  Vec vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = (a.at(i) * b.at(i));
  return vec;
}

Vec::~Vec() { delete[] arr; }