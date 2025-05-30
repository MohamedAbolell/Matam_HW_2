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
MataMvidia:: MataMvidia(const MataMvidia& matamVidia):
    movieName(matamVidia.movieName),
    creatorName(matamVidia.creatorName),
    frames(nullptr),
    length(matamVidia.length)
{
    if(matamVidia.frames!=nullptr){
        frames = new Matrix[length];
        for (int i = 0; i < length; i++){
            frames[i] = matamVidia.frames[i];
        }
    }
}

MataMvidia::~MataMvidia(){
    if(frames!=nullptr){
        delete[] frames;
        frames = nullptr;
    }
}
MataMvidia& MataMvidia:: operator= (const MataMvidia& matamVidia){
    if (this == &matamVidia){
        return *this;
    }
    if(frames!=nullptr){
        delete[] frames;
        frames = nullptr;
    }
    movieName = matamVidia.movieName;
    creatorName = matamVidia.creatorName;
    length = matamVidia.length;
    if(matamVidia.frames!=nullptr){
        frames = new Matrix[matamVidia.length];
        for (int i = 0; i < length; i++){
            frames[i] = matamVidia.frames[i];
        }
    }
    return *this;
}
