#pragma once
#include <vector>
#include "Vector.h"

class Matrix
{
private:
	std::vector<std::vector<float>> mat;
	unsigned rows;
	unsigned cols;
public:
	Matrix();

	Matrix(const Matrix& other);
	Matrix(unsigned, unsigned);
	Matrix(unsigned, unsigned, int);
	//Matrix(Matrix&);

	Matrix& operator=(Matrix);
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);
	Matrix transpose();

	Matrix operator+ (float &x);
	Matrix operator- (float &x);
	Matrix operator* (float &x);
	Matrix operator/ (float &x);

	Vector operator*(const Vector& v);

	float& operator()(const unsigned& row, const unsigned& col);

	void print();

	unsigned getRows() const;
	unsigned getCols() const;

	~Matrix();
};

