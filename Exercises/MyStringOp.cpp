// String.cpp
#include "MyString.h"
#include<cstring>
#include<string>
#pragma warning (disable:4996)

MyString::MyString(const char* s)
{
    if (s)
    {
        len = strlen(s);
        if (str)
            delete[] str;
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);
    }
    else
        str = nullptr;
}

MyString::MyString(const MyString& ms)
    : MyString(ms.str)
{
}
MyString& MyString::operator=(const MyString& ms)
{
    len = ms.len;

    if (str)
        delete[] str;

    if (ms.str)
    {
        len = strlen(ms.str);
        str = new char[len + 1];
        strcpy_s(str, len + 1, ms.str);
    }
    else
        str = nullptr;

    return *this;
}

MyString::~MyString()
{
    if (str) //very important!!!
        delete[] str;
    str = nullptr;
}
MyString MyString::operator+(const MyString& ms) const
{
    int sizeI = len; //The size of the first string.
    int sizeII = ms.len; //The size of the second string.
    char* temp = new char[sizeI + sizeII + 1]; //Build string with the new length.
    strcpy(temp, str); //copy the first stirng to the new one.
    strcpy(temp , ms.str); //copy the second stirng to the new one.

    MyString x(temp);

    return x;
}

bool MyString::operator==(const MyString& ms) const
{
    return !strcmp(str, ms.str);
}

bool MyString::operator<(const MyString& ms) const
{
    return strcmp(str, ms.str)<0;
}

bool MyString::operator>(const MyString& ms) const
{
    return strcmp(str, ms.str)>0;
}

bool MyString::operator<=(const MyString& ms) const
{
    return *this<ms || *this == ms;
}

bool MyString::operator>=(const MyString& ms) const
{
    return *this > ms || *this == ms;
}

bool MyString::operator!=(const MyString& ms) const
{
    return strcmp(str, ms.str);
}

char & MyString::operator[](int index) 
{
    if(index < len && index>=0)
    return str[index];

    //If the input isn't healthy - exit the program.
    cout << "ERROR" << endl;
    exit(0);
}

MyString MyString:: insert(int index, const char* ms)
{
    if (index < len && index >=0) //If the index is between 0 to the end of the string.
    {

        char* temp = new char[strlen(ms) + len + 1];

        //Copy the first string until the index
        strncpy(temp,str,index);

        //Copy the second string
       strcat(temp, ms);

       //Copy the first string from thee index until the end
            strcat(temp, str+index); 

       return temp;
    }
    else
    {
        cout << "ERROR" << endl;
        return "";
    }
}

MyString MyString::operator*(const int num) const
{
    char* temp;
    temp = new char[len * num + 1]; 

    for (int i = 0; i < num; i++) //copy the string 'num' times
        strcpy_s(temp + i * len, len + 1, str);

    MyString s(temp);

    return s;
}

char* MyString:: getStr()
{
    char* temp = new char[len+1];
    for (int i = 0; i < len; i++)
        temp[i] = str[i];
    return temp;
}
ostream& operator<<(ostream& os, const MyString& ms)
{
    if (ms.str)
        os << ms.str << endl;

    return os;
}

istream& operator>>(istream& is, MyString& ms)
{
    if (ms.str)
        delete ms.str;

    //Receive the string
    char temp[100];
    is >> temp;

    //Build ms witj the new valus.
    ms.len = strlen(temp);
    ms.str = new char[ms.len + 1];
    strcpy_s(ms.str, ms.len, temp);

    return is;
}

MyString::MyString(MyString&& ms)
{  // move constructor

    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr; //very important!!!

    cout << "move ctor" << endl;
}



MyString& MyString::operator=(MyString&& ms)
{ // move assignment operator

    if (str)
        delete[] str;

    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr;

    cout << "move assign" << endl;

    return *this;
}
