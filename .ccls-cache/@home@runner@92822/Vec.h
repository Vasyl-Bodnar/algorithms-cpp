#pragma once
class Vec {
	int _size;
	int _cap;
	int* arr;

public:
	Vec();
	Vec(int);
	Vec(int, int);

	const int size() const;
	const int cap() const;
	void push(int);
	void pop();
	void insert(int, int);
	void remove(int);
	void reserve(int);
	int index_of(int);
	const int at(int) const;
	int operator[](int);
	friend Vec operator+(const Vec&, int);
	friend Vec operator*(const Vec&, int);
	friend Vec operator+(const Vec&);
	friend Vec operator*(const Vec&);
	~Vec();
};