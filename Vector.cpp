#include "Vector.h"
#include <iostream>
#include <cmath>
#include <algorithm>

Vector::Vector(int n) {
	if (n < 2)
		n = 2;
	this->n = n;
	x = new double[n];
	for (int i = 0; i < n; i++)
		x[i] = 0;
}
Vector::Vector(int* x, int n) {
	this->n = n;
	this->x = new double[n];
	for (int i = 0; i < n; i++) {
		this->x[i] = x[i];
	}
}
Vector::Vector(Vector& a) {
	n = a.n;
	x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = a.x[i];
	}
}
Vector Vector::operator=(const Vector& a) {
	delete[] x;
	n = a.n;
	x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = a.x[i];
	}
	return *this;
}
double Vector::operator[](int k) const{
	if (k >= n)
		k = n - 1;
	if (k < 0)
		k = 0;
	return x[k];
}
double& Vector::operator[](int k) {
	if (k < 0)
		k = 0;
	if (k >= n) {
		double* arr = new double[n];
		for (int i = 0; i < n; i++) {
			arr[i] = x[i];
		}
		delete[] x;
		x = new double[k + 1];
		x = arr;
		for (int i = n; i <= k; i++) {
				x[i] = 0;
		}
		n = k + 1;
	}
	return x[k];
}
bool Vector::operator==(const Vector& a) const {
	int l = std::max(n, a.n);
	double m, k;
	for (int i = 0; i < l; i++) {
		if (i >= n)
			m = 0;
		else
			m = x[i];
		if (i >= a.n)
			k = 0;
		else
			k = a.x[i];
		if (m != k)
			return 0;
	}
	return 1;
}
bool Vector::operator!=(const Vector& a) const {
	if (*this == a) {
		return 0;
	}
	return 1;
}
Vector& Vector::operator+=(const Vector& a) {
	for (int i = 0; i < a.n; i++) {
		if (i >= n) {
			(*this)[i] = a[i];
		}
		else {
			(*this)[i] += a[i];
		}
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& a) {
	for (int i = 0; i < a.n; i++) {
		if (i >= n) {
			(*this)[i] = (-1) * a[i];
		}
		else {
			(*this)[i] -= a[i];
		}
	}
	return *this;
}
Vector Vector::operator+(const Vector& a) {
	Vector b = *this;
	b += a;
	return b;
}
Vector Vector::operator-(const Vector& a) {
	Vector b = *this;
	b -= a;
	return b;
}
double Vector::operator*(const Vector& a) const {
	int l = std::min(n, a.n);
	double sum = 0;
	for (int i = 0; i < l; i++) {
		sum += (x[i] * a.x[i]);
	}
	return sum;
}
double Vector::distance(const Vector& a) const {
	int l;
	double sum = 0, m, k;
	if (n > a.n)
		l = n;
	else
		l = a.n;
	for (int i = 0; i < l; i++) {
		if (n <= l)
			m = x[i];
		else
			m = 0;
		if (a.n <= l)
			k = a.x[i];
		else
			k = 0;
		sum += ((m - k) * (m - k));
	}
	return sqrt(sum);
	
}

std::istream& operator>>(std::istream& in, Vector& a) {
	delete[] a.x;
	in >> a.n;
	a.x = new double[a.n];
	for (int i = 0; i < a.n; i++) {
		in >> a.x[i];
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, const Vector& a) {
	for (int i = 0; i < a.n; i++) {
		out << a.x[i] << " ";
	}
	out << std::endl;
	return out;
}