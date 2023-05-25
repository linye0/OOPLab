#include "myString.h"
#include <iostream>

using namespace std;

MyString::MyString(const char *pData) {
    if (pData == nullptr) {
        mpData= new char[1];
        mpData[0] = '\0';
    } else {
        int length = strlen(pData);
        mpData = new char[length + 1];
        strcpy(mpData, pData);
    }
}

MyString::MyString(const MyString & obj) {
    int length = strlen(obj.mpData);
    mpData = new char[length + 1];
    strcpy(mpData, obj.mpData);
}

MyString::~MyString() {
    delete[] mpData;
}

MyString& MyString::operator =(const MyString & obj) {
    if (this == &obj) {
        return *this;
    }
    delete[] mpData;
    int length = strlen(obj.mpData);
    mpData = new char[length + 1];
    strcpy(mpData, obj.mpData);
    return *this;
}

MyString& MyString::operator +=(const MyString& another) {
    int length1 = strlen(mpData);
    int length2 = strlen(another.mpData);
    char* newData = new char[length1 + length2 + 1];
    strcpy(newData, mpData);
    strcat(newData, another.mpData);
    delete[] mpData;
    mpData = newData;
    return *this;
}

MyString::operator char* () const{
    return mpData;
}


const MyString  operator +  (const MyString & string1,const MyString & string2) {
    MyString str1(string1);
    str1 += string2;
    return str1;
}

ostream& operator<<(ostream& os, const MyString& str){
    os << (char*)str;
    return os;
}
