#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray
{
public:
    DynamicArray(int row = 0, int col = 0): mCol(col), mRow(row) {
        a = new int*[mRow];
        for (int i = 0; i < mRow; i++) {
            a[i] = new int[mCol];
        }
    }

    ~DynamicArray() {
        for (int i = 0; i < mRow; i++) {
            delete[] a[i];
        }
        delete[] a;
    }

    int* operator [] (int i) {
        return a[i];
    }

private:
    int ** a;
    int mCol;
    int mRow;
};

#endif // DYNAMIC_ARRAY_H
