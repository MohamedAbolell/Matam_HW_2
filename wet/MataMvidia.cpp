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
const Matrix& MataMvidia:: operator[] (int index) const{
    if (index < 0 || index >= length || frames == nullptr){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[index];
}
Matrix& MataMvidia:: operator[] (int index){
    if (index < 0 || index >= length || frames == nullptr){
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[index];
}
MataMvidia& MataMvidia::operator+= (const MataMvidia& matamVidia){
    int newLength = length + matamVidia.length;
    Matrix* newFrames = new Matrix[newLength];
    for(int i = 0; i < length; i++){ // copy left movie first
        newFrames[i] = frames[i];
    }
    for(int j = 0; j < matamVidia.length; j++){// copy right movie
        newFrames[length+j] = matamVidia.frames[j];
    }
    if(frames != nullptr){
        delete[] frames;
    }
    length = newLength;
    frames = newFrames;
    return *this;
}
MataMvidia& MataMvidia:: operator+= (const Matrix& matrix){
    Matrix array[] = {matrix};
    MataMvidia newMovie("","",array,1);
    return *this += newMovie;
}
MataMvidia MataMvidia:: operator+(const MataMvidia& matamVidia2)const {
    MataMvidia newMovie= *this;
    return newMovie += matamVidia2;
}



