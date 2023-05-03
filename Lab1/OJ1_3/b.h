#ifndef B_H
#define B_H

using namespace std;

class B {
public:
      B(A& aA) { pA = &aA; }
      void Func() {
           cout<<"This is member function Func()"<<endl;
      }
      void NewFunc()
      {
          pA->OtherFunc();
      }

private:
      A  *  pA;
};

#endif // B_H
