#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
  public:
    MyString(const char* pData= NULL);		// 普通构造函数
    MyString(const MyString &);	        	// 拷贝构造函数
    ~ MyString();					// 析构函数
    MyString& operator =(const MyString &);	// 赋值函数
    MyString& operator += (const MyString &);
    operator char* () const;                 	// 自动转换函数
  private:
    char  	*mpData;				// 用于保存字符串
   };

const MyString  operator +  (const MyString &,const MyString &);//字符串连接
ostream& operator<<(ostream& os, const MyString& str); 		//定向输出

#endif // MYSTRING_H
