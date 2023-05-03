#ifndef CRYPTER_H
#define CRYPTER_H

#include <iostream>
#include "TRandom.h"
using namespace std;

class Crypter
{
public:
    Crypter(long key_, unsigned char data_[], int len_): key(key_), len(len_) {
        data = new unsigned char[len_];
        for (int i = 0; i < len_; i++) {
            data[i] = data_[i];
        }
    }
    void code() {
        TRandom rnd(key);
        for (int i = 0; i < len; i++) {
            int rndNum = rnd.Integer();
            data[i] = data[i] ^ rndNum;
        }
    }
    void print() {
        for (int i = 0; i < len; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
private:
    long key;
    int len;
    unsigned char* data;
};

#endif // CRYPTER_H
