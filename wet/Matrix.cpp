#include "Matrix.h"

Matrix::Matrix() : rows(0), cols(0), data(nullptr) {};

Matrix::Matrix(const Matrix& matrix): rows(matrix.rows), cols(matrix.cols), data(nullptr) {
    if(matrix.data != nullptr) {
        data = new int[rows*cols];
    }
    for (int i = 0; i < rows*cols; i++) {
        data[i] = matrix.data[i];
    }
}
Matrix::~Matrix() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}
Matrix& Matrix::operator=(const Matrix& matrix){
    if (this == &matrix) {
        return *this;
    }
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    if (matrix.data != nullptr) {
        data = new int[matrix.rows * matrix.cols];
        for (int i = 0; i < matrix.rows*matrix.cols; i++) {
            this->data[i] = matrix.data[i];
        }
    }
    return *this;
}
const int& Matrix::operator()(const int row , const int col) const{
    if (row < 0 || col < 0 || row >= rows || col >= cols || data == nullptr) {
        exitWithError (MatamErrorType::OutOfBounds);
    }
    return data[row * cols + col];
}

int& Matrix::operator()(const int row , const int col){
    if (row < 0 || col < 0 || row >= rows || col >= cols || data == nullptr) {
        exitWithError (MatamErrorType::OutOfBounds);
    }
    return data[row * cols + col];
}
std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
    if(matrix.rows == 0 || matrix.cols == 0) {
        return os;
    }
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << "|" << matrix(i,j);
        }
        os << "|" << std::endl;
    }
    return os;
}


