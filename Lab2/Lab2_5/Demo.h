#ifndef DEMO_H
#define DEMO_H

#include <iostream>

using namespace std;

class Demo
{
public:
    void addValue(int value) {mNum += value;}
    void showValue() const {cout << "Value= " << mNum << endl;}
    static Demo* getInstance() {
        if (mInstance == nullptr) {
            mInstance = new Demo();
        }
        return mInstance;
    }
private:
    static Demo* mInstance;
    int mNum;
    Demo() {
        mNum = 0;
    }
    Demo& operator= (const Demo&) = delete;
    Demo(const Demo&) = delete;
};

#endif // DEMO_H
