#pragma once
class Vec {
	int _size;
	int _cap;
	int* arr;

public:
	Vec();
	Vec(int);
	Vec(int, int);

	int size();
	int cap();
	void push(int);
	void insert(int, int);
	void reserve(int);
	int at(int);
	int operator[](int);
	~Vec();
};