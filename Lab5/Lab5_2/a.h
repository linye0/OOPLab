#ifndef A_H
#define A_H

#include <iostream>
using namespace std;

class A
{
public:
     A(int num):data(num) {}
     void AFuncs() {cout<<"This is A \'s public function!"<<endl;}
protected:
     int data;
};
class B
{
public:
     B(int num):value(num) {}
     void BFuncs() {cout<<"This is B \'s public function!"<<endl;}
protected:
     int value;
};

/*
class C:public A,private B
{
public:
    C(int num1,int num2,int y): A(num1), B(num2), yyy(y) {}
     void MyFuncs()
          {
            BFuncs();
            cout<<"This function call B::BFuncs() !"<<endl;
          }
private:
     int yyy;
};
*/

class C: public A{
public:
    C(int num1, int num2, int y) : A(num1), b(num2), yyy(y) {}
    void MyFuncs()
         {
           b.BFuncs();
           cout<<"This function call B::BFuncs() !"<<endl;
         }
    ~C() {}
    C(const C& other) : A(other), b(other.b), yyy(other.yyy) {}
    C& operator=(const C& other) {
        if (&other != this) {
            A::operator=(other);
            this->b = other.b;
            this->yyy = other.yyy;
        }
        return *this;
    }
    void AFuncs() {cout<<"This is A \'s public function!"<<endl;}
private:
    B b;
    int yyy;
};

#endif // A_H
