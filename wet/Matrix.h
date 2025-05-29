#pragma once

#include <iostream>
#include "Utilities.h"

class Matrix {
private:
    int rows;
    int cols;
    int *data;

public:
    Matrix();

    Matrix(int rows, int cols, int value = 0);

    Matrix(const Matrix& matrix);

    Matrix& operator=(const Matrix& matrix);

    ~Matrix();

    int& operator()(const int row , const int col);

    const int& operator()(const int row , const int col) const;

    Matrix operator+(const Matrix& matrix2) const;
    Matrix operator-(const Matrix& matrix2) const;
    Matrix operator*(const Matrix& matrix2) const;
    Matrix& operator+=(const Matrix& matrix2);
    Matrix& operator -= (const Matrix& matrix2);
    Matrix&  operator *= (const Matrix& matrix2);


    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);


};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
