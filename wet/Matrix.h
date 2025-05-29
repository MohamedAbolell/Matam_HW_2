#pragma once

#include <iostream>
#include "Utilities.h"

class Matrix {
private:
    int rows;
    int cols;
    int *data;
    static double CalcDeterminant(const Matrix& matrix, const int beginIndex);


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

    Matrix operator-() const;

    Matrix operator*(const int num) const;

    Matrix& operator*=(const int num);

    Matrix rotateClockwise() const;

    Matrix rotateCounterClockwise() const;

    Matrix transpose() const;

    static double CalcFrobeniusNorm(const Matrix& matrix);

    static double CalcDeterminant(const Matrix& matrix);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend bool operator==(const Matrix& matrix1, const Matrix& matrix2);


};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
bool operator==(const Matrix& matrix1, const Matrix& matrix2);
bool operator!=(const Matrix& matrix1, const Matrix& matrix2);

