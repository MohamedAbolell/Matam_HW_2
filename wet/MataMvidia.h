#pragma once

#include <iostream>
#include <Matrix.h>
class MataMvidia {

private:
    std::string movieName;
    std::string creatorName;
    Matrix* frames;
    int length;
public:
    MataMvidia(const std::string& movieName="" , const std::string& creatorName="" , const Matrix* array=nullptr, int length=0);

    MataMvidia(const MataMvidia& matamVidia);

    ~MataMvidia();

    MataMvidia& operator= (const MataMvidia& matamVidia);

    const Matrix& operator[] (int index) const;

    Matrix& operator[] (int index);

    MataMvidia& operator+= (const MataMvidia& matamVidia);

    MataMvidia& operator+= (const Matrix& matrix);

    MataMvidia operator+(const MataMvidia& matamVidia2) const;

    friend std:: ostream& operator<<(std::ostream& os, const MataMvidia& matamVidia);

};

std:: ostream& operator<<(std::ostream& os, const MataMvidia& matamVidia);
