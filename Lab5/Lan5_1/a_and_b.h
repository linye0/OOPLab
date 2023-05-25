#ifndef A_AND_B_H
#define A_AND_B_H

#include <iostream>

using namespace std;

class A
{
public:
    A(int num):data1(num){}
    ~A() {
        cout<<" Destory A"<<endl;
    }
    void  f() const {
        cout<<" Excute A::f() ";
        cout<<" Data1="<<data1<<endl;
    }
    void g() {
        cout<<" Excute A::g() "<<endl;
    }
protected:
     int data1;
};

class B:public A
{
public:
    B(int num1,int num2):A(num1),data2(num2){}
    ~B()    { cout<<" Destory B"<<endl; }
    void f( ) const
    {
        cout<<" Excute B::f() ";
        cout<<" Data1="<< data1;
        cout<<" Data2="<<data2<<endl;
    }
    void f(int n) const
    {
        cout<<" Excute B::f(int) ";
        cout<<" n="<<n;
        cout<<" Data1="<< data1;
        cout<<" Data2="<<data2<<endl;
    }
    void h() {
        cout<<" Excute B::h() "<<endl;
    }
private:
    int data2;
};


#endif // A_AND_B_H
