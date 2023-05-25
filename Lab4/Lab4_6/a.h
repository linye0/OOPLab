#ifndef A_H

#define A_H

#include <iostream>

using namespace std;

class A
{
public:
    A(int m = 0): mData(m) {}
    static void* operator new(size_t size) {
        cout << "operator new" << endl;
        ++mCount;
        mUsedBytes += size;
        return ::operator new(size);
    }
    static void operator delete(void* ptr, size_t size) {
        cout << "operator delete" << endl;
        --mCount;
        mUsedBytes -= size;
        ::operator delete(ptr);
    }
    static void* operator new[](size_t size) {
        cout << "operator new[]" << endl;
        ++mCount;
        mUsedBytes += size;
        return ::operator new[](size);
    }
    static void operator delete[](void* ptr, size_t size) {
        cout << "operator delete[]" << endl;
        --mCount;
        mUsedBytes -= size;
        ::operator delete[](ptr);
    }
private:
    int mData;
    static int mCount;
    static int mUsedBytes;
};

#endif // A_H
