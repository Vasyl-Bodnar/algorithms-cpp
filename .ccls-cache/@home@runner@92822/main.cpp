#include <iostream>
#include "Vec.h"

using namespace std;

void print(const Vec &vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec.at(i) << endl;
}

int main() {
	Vec vec(3,3);
	print(vec);

	return 0;
}