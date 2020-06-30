#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Vector a, b, c;
	cin >> a;
	cin >> b;
	//cin >> c;
	cout << (a += b) << endl;
	cout << a << endl;
	cout << (a * b) << endl;
	//c = a + b + b;
	//cout << c << endl;
	return 0;
}