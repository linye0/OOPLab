#ifndef A_H
#define A_H

using namespace std;

class A {
public:
    static int aStaticInt;
    void setAObj() {
        A::aStaticInt = 100;
    }
    static void setA(){
        A::aStaticInt = 0;
    }
    static void addA(int i = 1){
        A::aStaticInt = A::aStaticInt + i;
    }
    static void showA() {
        cout << A::aStaticInt << endl;
    }
    void Display() const {
           cout<<"The argment is NULL"<<endl;
    }

    void Display(const char * str) const {
           cout<<"The argment is "<<str<<endl;
    }
    void OtherFunc() {
            cout << "This is pA otherFunc" << endl;
    }
private:

};

int A::aStaticInt = 0;

#endif // A_H
