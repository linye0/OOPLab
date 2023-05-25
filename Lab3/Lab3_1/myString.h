#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
  public:
    MyString(const char* pData= NULL);		// ��ͨ���캯��
    MyString(const MyString &);	        	// �������캯��
    ~ MyString();					// ��������
    MyString& operator =(const MyString &);	// ��ֵ����
    MyString& operator += (const MyString &);
    operator char* () const;                 	// �Զ�ת������
  private:
    char  	*mpData;				// ���ڱ����ַ���
   };

const MyString  operator +  (const MyString &,const MyString &);//�ַ�������
ostream& operator<<(ostream& os, const MyString& str); 		//�������

#endif // MYSTRING_H
