#include "MataMvidia.h"
using std::string;

MataMvidia:: MataMvidia(const string& movieName , const string& creatorName , const Matrix* array, int length):
        movieName(movieName),
        creatorName(creatorName),
        frames(nullptr),
        length(length)
{
    if(array != nullptr){
        frames = new Matrix[length];
        for (int i = 0; i < length; i++){
            frames[i] = array[i];
        }
    }
}
