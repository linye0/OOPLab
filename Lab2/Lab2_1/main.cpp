#include <iostream>
#include <vector>
#include <cmath>

#include "Crypter.h"
#include "TRandom.h"
using namespace std;

// 利用练习一中的TRandom类，实现指定全局函数，以便完成字节数组的加密和解密。
void Coder(unsigned char data[], int len,  unsigned long key) {
    TRandom Rnd(key);
    for (int i = 0; i < len; i++) {
        int rndNum = Rnd.Integer();
        data[i] = data[i] ^ rndNum;
    }
}

void Coder(unsigned char data[], int len,  TRandom rand, unsigned long key) {
    for (int i = 0; i < len; i++) {
        int rndNum = rand.Integer();
        data[i] = data[i] ^ rndNum;
    }
}

void print(unsigned char data[], int len) {
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}



int main()
{
    TRandom Rnd(114514);
    unsigned char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int len = sizeof(data) / sizeof(unsigned char);
    Crypter crypter(114514, data, len);
    crypter.print();
    crypter.code();
    crypter.print();
    crypter.code();
    crypter.print();
    return 0;
}
