#include "max.h"

int max(int a,int b) {
    return a > b? a: b;
}
/*
int max(const int a, const int b){
    return a > b? a: b;
}
*/
/*
int max(int& a ,int& b) {
    return a > b? a: b;
}
*/
/*
int& max(const int& a,const int& b) {
    int* ret = new int(a);
    if (b > a) *ret = b;
    return *ret;
}
*/
