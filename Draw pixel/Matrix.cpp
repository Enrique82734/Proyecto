#include "pch.h"
#include "Matrix.h"
#include <iostream>


Matrix::Matrix()
{
}

Matrix::Matrix(const Matrix & other)
{
	mat = other.mat;
	rows = other.getRows();
	cols = other.getCols();
}

Matrix::Matrix(unsigned _rows, unsigned _cols)
{
	mat.resize(_rows);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(_cols, 0);
	}
	rows = _rows;
	cols = _cols;
}

Matrix::Matrix(unsigned _rows, unsigned _cols, int valor)
{
	mat.resize(_rows);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(_cols);
	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			this->mat[i][j] = valor;
		}
	}
	rows = _rows;
	cols = _cols;
}

Matrix & Matrix::operator=(Matrix other)
{
	if (&other == this) {
		return *this;
	}

	unsigned new_rows = other.getRows();
	unsigned new_cols = other.getCols();

	mat.resize(new_rows);

	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(new_cols);
	}

	for (unsigned i = 0; i < new_rows; i++) {
		for (unsigned j = 0; j < new_cols; j++) {
			mat[i][j] = other(i, j);
		}
	}

	rows = new_rows;
	cols = new_cols;
	return *this;
}

Matrix Matrix::operator+(Matrix & _mat)
{
	Matrix temp(rows, cols, 0);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			temp(i, j) = this->mat[i][j] + _mat(i, j);
		}
	}
	return temp;
}

Matrix Matrix::operator-(Matrix & _mat)
{
	Matrix temp(rows, cols, 0);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			temp(i, j) = this->mat[i][j] - _mat(i, j);
		}
	}
	return temp;
}

Matrix Matrix::operator*(Matrix & _mat)
{
	Matrix temp(rows, cols, 0);
	int varTemp;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < cols; k++) {
				temp(i, j) += this->mat[i][k] * _mat(k, i);
			}
		}
	}
	return temp;
}

Matrix Matrix::transpose()
{
	Matrix temp(rows, cols, 0);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			temp(i, j) = mat[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mat[i][j] = temp(j, i);
		}
	}
}

float & Matrix::operator()(const unsigned & row, const unsigned & col)
{
	return this->mat[row][col];
	// TODO: insertar una instrucción return aquí
}

void Matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << mat[i][j];
		}
	}
	std::cout << "\n";
}

unsigned Matrix::getRows() const
{
	return this->rows;
}

unsigned Matrix::getCols() const
{
	return this->cols;
}

Matrix::~Matrix()
{
}
