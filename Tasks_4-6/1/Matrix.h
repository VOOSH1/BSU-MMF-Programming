#pragma once
#include <iostream>
#include "Exception.h"

class Matrix
{
private:
	int n;
	int** matrix;
public:
	~Matrix();
	Matrix();
	Matrix(const int* const*, const int&);
	Matrix(const Matrix&);
	int get_n() const;
	const int * const * get_matrix() const;
	int get_elemnt(const int&, const int&) const;
	void set_matrix_and_n(const int * const *, const int&);
	Matrix& operator= (const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend void funct(Matrix*, const int&, const int*, int**);
};