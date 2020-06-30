#pragma once
#include <iostream>
#include <fstream>

class Vector
{
	double* x;
	int n;
	friend std::istream& operator>>(std::istream& in, Vector& a);
	friend std::ostream& operator<<(std::ostream& out, const Vector& a);
public:
	explicit Vector(int n = 2);
	Vector(int* x, int n);
	Vector(Vector& a);
	Vector operator=(const Vector& a);
	double operator[](int k) const;
	double& operator[](int k);
	bool operator==(const Vector& a) const;
	bool operator!=(const Vector& a) const;
	Vector operator+(const Vector& a);
	Vector operator-(const Vector& a);
	Vector& operator+=(const Vector& a);
	Vector& operator-=(const Vector& a);
	double operator*(const Vector& a) const;
	double distance(const Vector& a) const;
	~Vector() {
		delete[] x;
	}
};