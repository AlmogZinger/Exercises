#include "Vector.h"         //homework targil 2 !

//-------------------------------------------------------
//  class StackVector
//  Stack implemented using Vector
//  Vector will grow as necessary to avoid overflow
//-------------------------------------------------------

template <class T>
class StackVector
{
public:
    // constructor requires a starting size
    StackVector( int capacity);
 

    // Stack operations
    void clear();
    bool isEmpty() const;
    T pop();
    void push(T value);
    T top() const;

protected:
    // data fields
    Vector<T> data;
};


//-------------------------------------------------------
//  class StackVector implementation
//-------------------------------------------------------


template <class T>
StackVector<T>::StackVector(int capacity) : data(capacityss)
{
    // create and initialize a Stack based on Vectors
}

template <class T>
void StackVector<T>::clear()
{
    // clear all elements from Stack, by setting
    // index to bottom of Stack
    data.clear();
}

template <class T>
bool StackVector<T>::isEmpty() const
{
    return data.getSize() == 0;
}

template <class T>
T StackVector<T>::pop()
{
    // return and remove the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data.delLast();
}

template <class T>
void StackVector<T>::push(T val)
{
    // push new value onto Stack
    data.insert(val);
}

template <class T>
T StackVector<T>::top() const
{
    // return the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data[data.getSize() - 1];
}

string inFixToPostfix(StackVector<char> infix)
{
    string str;
    StackVector<char> stk(1000);
    while (!infix.isEmpty()) //If the string isn't empty
    {
        char ch = infix.pop();
        switch (ch) {
            case '(':
                stk.push(ch);
            break;
            case ')':
               while (stk.top() != '(')
                  {
                    str += stk.pop();
                    str += ' ';
                   }
                 stk.pop();
                 break;
            case '*':
            case '/':
                //While the top of the stack isnt ) or oporation in lower priority
                while (stk.top() != '(' && stk.top() != '+' && stk.top() != '-')
                {
                    str += stk.pop();
                    str += ' ';
                } //insert to str the stack value.
                stk.push(ch);
                    break; 
            case '+':
            case '-':
                //While the top of the stack isnt )
                while (stk.top() != '(')
                {
                    str += stk.pop();
                    str += ' ';
                }
                stk.push(ch);
                break;
            default: if (ch >= '0' && ch <= '9') //If this a number
                stk.push(ch);
        }       
        ch = infix.pop();
    }
   while (!stk.isEmpty())
   {
       str += stk.pop();
       str += ' ';
   }

   return str;
    }


int calcPostfix(string postFix)
{
    StackVector<int> stk(1000);

}
