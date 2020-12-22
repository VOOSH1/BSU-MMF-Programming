#include "Matrix.h"

Matrix::~Matrix()
{
	for (int i( 0 ); i < this->n; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

Matrix::Matrix()
{
	this->n = 0;
	this->matrix = nullptr;
}

Matrix::Matrix(const int* const* matrix, const int& n)
{
	this->n = n;
	try {
		if (n <= 0)
			throw Exception( "Ошибка! Некорректное значение для выделения памяти" );
		this->matrix = new (std::nothrow) int* [n];
		if (!this->matrix)
			throw Exception( "Ошибка выделения памяти!" );
		for (int i( 0 ); i < n; ++i)
		{
			this->matrix[i] = new (std::nothrow) int[n];
			if (!this->matrix[i])
				throw Exception( "Ошибка выделения памяти!" );
		}
	}
	catch (const Exception & e)
	{
		std::cout << e.what() << '\n';
		system("pause");
		exit(1);
	}
	for (int i( 0 ); i < n; ++i)
		for (int j( 0 ); j < n; ++j)
			this->matrix[i][j] = matrix[i][j];
}

Matrix::Matrix(const Matrix& matr)
{
	this->n = matr.n;
	if (matr.n == 0)
		this->matrix = nullptr;
	else
	{
		try {
			this->matrix = new (std::nothrow) int* [matr.n];
			if (!this->matrix)
				throw Exception( "Ошибка выделения памяти!" );
			for (int i( 0 ); i < matr.n; ++i)
			{
				this->matrix[i] = new (std::nothrow) int[matr.n];
				if (!this->matrix[i])
					throw Exception( "Ошибка выделения памяти!" );
			}
		}
		catch (const Exception & e)
		{
			std::cout << e.what() << '\n';
			system("pause");
			exit(1);
		}
		for (int i( 0 ); i < matr.n; ++i)
			for (int j( 0 ); j < matr.n; ++j)
				this->matrix[i][j] = matr.matrix[i][j];
	}
}

int Matrix::get_n() const
{
	return this->n;
}

const int* const* Matrix::get_matrix() const
{
	return this->matrix;
}

int Matrix::get_elemnt(const int& i, const int& j) const
{
	try {
		if (((i >= 0) && (i < this->n)) && ((j >= 0) && (j < this->n)))
			return this->matrix[i][j];
		else
			throw Exception( "Ошибка! Некорректное значение индекса" );
	}
	catch (const Exception & e)
	{
		std::cout << e.what() << '\n';
		system("pause");
		exit(1);
	}
}

void Matrix::set_matrix_and_n(const int* const* matrix, const int& n)
{
	*this = Matrix(matrix, n);
}

Matrix& Matrix::operator=(const Matrix& matr)
{
	if (this == &matr)
		return *this;
	for (int i( 0 ); i < this->n; ++i)
		delete[] matrix[i];
	delete[] matrix;
	this->n = matr.n;
	if (matr.n == 0)
		this->matrix = nullptr;
	else
	{
		try {
			this->matrix = new (std::nothrow) int* [matr.n];
			if (!this->matrix)
				throw Exception( "Ошибка выделения памяти!" );
			for (int i( 0 ); i < matr.n; ++i)
			{
				this->matrix[i] = new (std::nothrow) int[matr.n];
				if (!this->matrix[i])
					throw Exception( "Ошибка выделения памяти!" );
			}
		}
		catch (const Exception & e)
		{
			std::cout << e.what() << '\n';
			system("pause");
			exit(1);
		}
		for (int i( 0 ); i < matr.n; ++i)
			for (int j( 0 ); j < matr.n; ++j)
				this->matrix[i][j] = matr.matrix[i][j];
	}
	return *this;
}

std::istream& operator>>(std::istream& sstream, Matrix& matr)
{
	for (int i( 0 ); i < matr.n; ++i)
		delete[] matr.matrix[i];
	delete[] matr.matrix;
	sstream >> matr.n;
	try {
		if (matr.n <= 0)
			throw Exception( "Ошибка! Некорректное значение для выделения памяти" );
		matr.matrix = new (std::nothrow) int* [matr.n];
		if (!matr.matrix)
			throw Exception( "Ошибка выделения памяти!" );
		for (int i( 0 ); i < matr.n; ++i)
		{
			matr.matrix[i] = new (std::nothrow) int[matr.n];
			if (!matr.matrix[i])
				throw Exception( "Ошибка выделения памяти!" );
		}
	}
	catch (const Exception & e)
	{
		std::cout << e.what() << '\n';
		system("pause");
		exit(1);
	}
	for (int i( 0 ); i < matr.n; ++i)
		for (int j( 0 ); j < matr.n; ++j)
			sstream >> matr.matrix[i][j];
	return sstream;
}

std::ostream& operator<<(std::ostream& sstream, const Matrix& matr)
{
	for (int i( 0 ); i < matr.n; ++i)
	{
		for (int j( 0 ); j < matr.n; ++j)
			sstream << matr.matrix[i][j] << " ";
		sstream << '\n';
	}
	return sstream;
}