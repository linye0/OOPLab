#ifndef A_AND_B_H
#define A_AND_B_H

class A {
public:
    A(int num):mData(num){    }
    ~A( ) {    }
    int GetData( ) const    { return mData; }
    void SetData(int data)  { mData = data; }
private:
    int mData;
};

class B {
public:
    B(int num = 0): pa(new A(num)), refCount(new int(1)) {}
    ~B(){
        if (--(*refCount) == 0) {
            delete refCount;
            delete pa;
        }
    }

    B(const B& rhs) : pa(rhs.pa), refCount(rhs.refCount) {
        (*refCount)++;
    }

    B& operator=(const B& rhs) {
        if (this != &rhs) {
            if (--(*refCount) == 0) {
                delete refCount;
                delete pa;
            }
            refCount = rhs.refCount;
            pa = rhs.pa;
            ++(*refCount);
        }
        return *this;
    }

    A operator->() const {
        return pa;
    }

    void GetData() const {
        pa->GetData();
    }

    void SetData(int data) {
        if (*refCount > 0) {
            --(*refCount);
            pa = new A(*pa);
            refCount = new int(1);
        }
        pa->SetData(Data);
    }

private:
    A* pa;
    int* refCount;
};

#endif // A_AND_B_H
