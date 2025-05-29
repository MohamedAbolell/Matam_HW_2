#pragma once

#include <iostream>

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

};