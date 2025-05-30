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

};

