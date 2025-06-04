#include "Matrix.h"
#include "Utilities.h"
#include <cmath>
Matrix::Matrix() : rows(0), cols(0), data(nullptr) {};

Matrix::Matrix(int rows, int cols,int value) : rows(rows), cols(cols), data(new int[rows*cols]) {
    for (int i = 0; i < rows*cols; i++) {
        data[i] = value;
    }
}

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
 Matrix Matrix:: operator+(const Matrix& matrix2) const {
	if (this->rows != matrix2.rows || this->cols != matrix2.cols) {
		exitWithError (MatamErrorType::UnmatchedSizes);
	}
  Matrix result(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++){
	  for (int j = 0; j < this->cols; j++){
 			result(i,j) = (*this)(i,j) + matrix2(i,j);
		}
	}
 	return result;
}
 Matrix Matrix:: operator-(const Matrix& matrix2) const{
    if (this->rows != matrix2.rows || this->cols != matrix2.cols) {
      exitWithError (MatamErrorType::UnmatchedSizes);
    }
    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows*this->cols; i++) {
      result.data[i] = this->data[i] - matrix2.data[i];
    }
    return result;
 }
 Matrix Matrix:: operator*(const Matrix& matrix2) const{
	if (this->cols != matrix2.rows) {
  		exitWithError ( MatamErrorType:: UnmatchedSizes);
 	}
 	Matrix result(this->rows, matrix2.cols);
 	for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
           	 for (int k = 0; k < matrix2.rows ; k++){
                result(i,j) += (*this)(i,k) * matrix2(k,j);
       		 }
      	 }
    }
   return result;
 }
Matrix& Matrix:: operator += (const Matrix& matrix2) {
  *this = *this + matrix2;
  return *this;
}
Matrix& Matrix:: operator -= (const Matrix& matrix2) {
  *this = *this - matrix2;
  return *this;
}
Matrix& Matrix:: operator *= (const Matrix& matrix2) {
  *this = *this * matrix2;
  return *this;
}
Matrix Matrix:: operator-() const {
    Matrix temp = *this;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp(i,j)= (*this)(i,j) * (-1);
        }
    }
    return temp;
}
Matrix Matrix:: operator*(const int num) const{
    Matrix temp = *this;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp(i,j)= (*this)(i,j)*num;
        }
    }
    return temp;
}
Matrix  operator*(const int num, const Matrix& matrix) {
    return  matrix * num;
}
Matrix& Matrix:: operator*=(const int num){
    *this = *this * num;;
    return *this;
}

bool operator==(const Matrix& matrix1, const Matrix& matrix2){
    if(!(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols )){
        return false;
    }
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            if(matrix1(i,j) != matrix2(i,j))
                return false;
        }
    }
    return true;

}
bool operator!=(const Matrix& matrix1, const Matrix& matrix2){
    return !(matrix1==matrix2);
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

Matrix Matrix:: rotateClockwise() const{
    Matrix clock(cols, rows);
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            clock(i,j) = (*this)(rows-1-j,i);
        }
    }
    return clock;
}
Matrix Matrix:: rotateCounterClockwise() const{
    Matrix counterClock(cols, rows);
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            counterClock(i,j) = (*this)(j,cols-1-i);
        }
    }
    return counterClock;
}

Matrix Matrix:: transpose() const{
    Matrix trans(cols, rows);
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            trans(i,j) = (*this)(j,i);
        }
    }
    return trans;
}
double Matrix:: CalcFrobeniusNorm(const Matrix& matrix){
    double sumOfSum=0;
    for (int i = 0; i < matrix.rows; i++){
        for (int j = 0; j < matrix.cols; j++){
            sumOfSum += pow(matrix(i,j),2) ;
        }
    }
    return sqrt(sumOfSum);
}
double Matrix:: CalcDeterminant(const Matrix& matrix, const int beginIndex){
    if(beginIndex == matrix.rows){
        return 0;
    }
    if(matrix.rows ==2){
        return matrix(0,0)*matrix(1,1) - (matrix(0,1)*matrix(1,0));
    }
    int mRows=0 , mCols=0;
    Matrix minor(matrix.rows-1, matrix.cols-1);
    for(int i=1;i<matrix.rows;i++){
        for(int j=0;j<matrix.cols;j++){
            if(j!=beginIndex){
                minor(mRows,mCols)=matrix(i,j);
                if(mCols+1 == matrix.cols-1){
                    mCols =0;
                    mRows++;
                }
                else{
                    mCols++;
                }
            }
        }
    }
    return (beginIndex%2==0? 1:-1) * matrix(0,beginIndex)*CalcDeterminant(minor, 0) + CalcDeterminant(matrix, beginIndex+1);
}
double Matrix:: CalcDeterminant(const Matrix& matrix){
    if(matrix.rows != matrix.cols){
        exitWithError(MatamErrorType::NotSquareMatrix);
    }
    if(matrix.rows == 0){
        return 0;
    }
    if(matrix.rows == 1){
        return matrix(0,0);
    }
    return CalcDeterminant(matrix, 0);
}

