#pragma once

#include <random>

namespace vec {

template <class T> class Vec {
public:
  Vec();
  Vec(int);
  Vec(int, T);
  Vec(int, T *);
  Vec(const Vec &);

  const int size() const;
  const int cap() const;
  const T *arr() const;
  void push(T);
  void pop();
  void sort();
  void insert(int, T);
  void remove(int);
  void reserve(int);
  bool empty();
  int index_of(T);
  const T at(int) const;
  T &operator[](int);
  ~Vec();

private:
  int _size;
  int _cap;
  T *_arr;
};

// Constructors
template <class T> Vec<T>::Vec() : _size(0), _cap(1), _arr(new T[0]) {}

template <class T>
Vec<T>::Vec(int size) : _size(size), _cap(size), _arr(new T[size]) {}

template <class T>
Vec<T>::Vec(int size, T n) : _size(size), _cap(size), _arr(new T[size]) {
  for (int i = 0; i < _size; i++)
    _arr[i] = n;
}

template <class T>
Vec<T>::Vec(int size, T *arr) : _size(size), _cap(size), _arr(new T[size]) {
  for (int i = 0; i < _size; i++)
    _arr[i] = arr[i];
}

template <class T> Vec<T>::Vec(const Vec &other) : Vec(other.size()) {
  for (int i = 0; i < other.size(); i++)
    _arr[i] = other.at(i);
}

// Read Access for private members
template <typename T> const int Vec<T>::size() const { return _size; }
template <typename T> const int Vec<T>::cap() const { return _cap; }
template <typename T> const T *Vec<T>::arr() const { return _arr; }

// Function Definitions
template <typename T> bool Vec<T>::empty() { return _size == 0; }

template <typename T> int Vec<T>::index_of(T n) {
  for (int i = 0; i < _size; i++)
    if (_arr[i] == n)
      return i;
  return -1; // or error
}

template <typename T> void swap(T& x, T& y) {
  T tmp = y;
  y = x;
  x = tmp;
}

template <typename T> bool sorted(T *arr, int size) {
  for (int i = 1; i < size; i++)
    if (arr[i] < arr[i - 1])
      return false;
  return true;
}

template <typename T> void Vec<T>::sort() {
  srand(time(NULL));
  while (!sorted(_arr, _size)) {
    int i = rand() % _size, j = rand() % _size;
    swap(_arr[i], _arr[j]);
  }
}

template <typename T> void Vec<T>::reserve(int cap) {
  if (cap > _cap) {
    _cap = cap;
    T *tmp = new T[_cap];
    for (int i = 0; i < _size; i++)
      tmp[i] = _arr[i];
    delete[] _arr;
    _arr = tmp;
  }
}

template <typename T> void Vec<T>::push(T n) {
  if (_size == _cap)
    reserve(_size * 2);
  _arr[_size++] = n;
}

// The code makes it impossible to go out of size bounds, so this should be fine
template <typename T> void Vec<T>::pop() { _size--; }

template <typename T> void Vec<T>::insert(int idx, T n) {
  if (idx < 0 || idx > _size)
    throw "Error! Out of Bounds";
  if (_size == _cap)
    reserve(_size * 2);
  for (int i = _size++; i > idx; i--)
    _arr[i] = _arr[i - 1];
  _arr[idx] = n;
}

template <typename T> void Vec<T>::remove(int idx) {
  if (idx < 0 || idx > _size--)
    throw "Error! Out of Bounds";
  for (int i = idx; i < _size; i++)
    _arr[i] = _arr[i + 1];
}

// Read-Only value
template <typename T> const T Vec<T>::at(int idx) const {
  return (idx > _size) ? throw "Error! Out of Bounds" : _arr[idx];
}

// Operator Overloading
// Mutable value
template <typename T> T &Vec<T>::operator[](int idx) {
  return (idx > _size) ? throw "Error! Out of Bounds" : _arr[idx];
}

template <typename T> Vec<T> operator+(const Vec<T> &a, const Vec<T> &b) {
  if (a.size() != b.size())
    throw "Error! Sizes do not match";
  Vec<T> vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = a.at(i) + b.at(i);
  return vec;
}

// Component Multiplication variant
// Will likely cause errors if enabled together with the dot product variant due
// to ambiguity template<typename T> Vec<T> operator*(const Vec<T>& a, const
// Vec<T>& b) {
//     if (a.size() != b.size())
//         throw "Error! Sizes do not match";
//     Vec<T> vec(a.size());
//     for (int i = 0; i < a.size(); i++)
//         vec[i] = a.at(i) * b.at(i);
//     return vec;
// }

// Dot product variant
template <typename T> int operator*(const Vec<T> &a, const Vec<T> &b) {
  if (a.size() != b.size())
    throw "Error! Sizes do not match";
  int sum = 0;
  for (int i = 0; i < a.size(); i++)
    sum += a.at(i) * b.at(i);
  return sum;
}

template <typename T> Vec<T> operator-(const Vec<T> &a, const Vec<T> &b) {
  if (a.size() != b.size())
    throw "Error! Sizes do not match";
  Vec<T> vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = a.at(i) - b.at(i);
  return vec;
}

template <typename T> Vec<T> operator/(const Vec<T> &a, const Vec<T> &b) {
  if (a.size() != b.size())
    throw "Error! Sizes do not match";
  Vec<T> vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] =
        (b.at(i) != 0) ? (a.at(i) / b.at(i)) : throw "Error! No Division by 0";
  return vec;
}

template <typename T = int> Vec<T> operator-(const Vec<T> &a, int other) {
  Vec<T> vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = (a.at(i) - other);
  return vec;
}

template <typename T = int> Vec<T> operator/(const Vec<T> &a, int other) {
  Vec<T> vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = (other != 0) ? (a.at(i) / other) : throw "Error! No Division by 0";
  return vec;
}

template <typename T = int> Vec<T> operator+(const Vec<T> &a, int other) {
  Vec<T> vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = (a.at(i) + other);
  return vec;
}

template <typename T = int> Vec<T> operator*(const Vec<T> &a, int other) {
  Vec<T> vec(a.size());
  for (int i = 0; i < a.size(); i++)
    vec[i] = (a.at(i) * other);
  return vec;
}

template <typename T> Vec<T>::~Vec() {
  delete[] _arr;
  _arr = nullptr;
}

} // namespace vec