/********************************
Uri Ehrlich 208967976 and Almog Zinger
Programming in C++
Exercise 8 question 1
The program runs an alghorithm of infix and postfix string
*********************************/



#pragma once
#include "Vector.h" 
#include "Stack.h"
#include <string> 
#include <cmath>
//homework targil 2 !
//-------------------------------------------------------
//  class StackVector
//  Stack implemented using Vector
//  Vector will grow as necessary to avoid overflow
//-------------------------------------------------------

template <class T>
class StackVector : public Stack<T> 
{
public:
    // constructor requires a starting size
    StackVector(unsigned int capacity);
    StackVector(const StackVector<T>& s);


    // Stack operations
    void clear() override;
    bool isEmpty() const override;
    T pop() override;
    void push(T value) override;
    T top()  override;

protected:
    // data fields
    Vector<T> data;
};





//-------------------------------------------------------
//  class StackVector implementation
//-------------------------------------------------------
template <class T>
StackVector<T>::StackVector(unsigned int capacity)
    : data(capacity)
{
    // create and initialize a Stack based on Vectors
}

template <class T>
StackVector<T>::StackVector(const StackVector& s): data(s.data)
{ /* copy constructor*/
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
    // return and remove the topmost element in the Stack
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
T StackVector<T>::top() 
{
    // return the intopmost element in the Stack
    if (isEmpty()) throw "Stack is empty";
    return data[data.getSize() - 1];
}

enum choise { LEFT = '(', RIGHT = ')', MULT = '*', DIV = '/', ADD = '+', SUB = '-' };// operators
string  infixToPostfix(string input)
{
    
    char ch; // the char from the input string
    string str = ""; // the new string
    StackVector<char> stk = StackVector<char>(100);
    int i = 0;
    ch = input[i];
    while (ch!='\0')
    {
        
        switch (ch)
        {

        case LEFT:
            stk.push(ch); // push '('
            break;
        case RIGHT:
        {
            while (stk.top() != '(' && !stk.isEmpty())
            {
                str += stk.pop(); // add to the string and pop from the stack
                str += " ";
            }
            if(stk.top() == '(')
              stk.pop(); // pop the '('
         
        }
        break;
        case SUB: 
        case ADD :
        case MULT:
        case DIV:
        {
           while (!stk.isEmpty()&& (stk.top() == MULT || stk.top() == DIV || stk.top() != LEFT ) )
            {
                str += stk.pop(); // add the operators to the string until '(' in the stack 
                str += " ";
                
            }
           stk.push(ch); // finally push the operator to the stack
        }
        break;
        default:
            
            if (ch <= '9' && ch >= '0') // ch is a digit
            {
                str += ch; // copy the current digit
                int j = i+1;
              
                while (input[j]!= '\0' && (input[j] <= '9' && input[j] >= '0')) // check if the next char is a digit. if so, it a number
                {
                    str += input[j]; // ad the next digit
                    j++;
                }
                str += " "; // space
                i = j-1; 
            }
        }

        i++; // forward the char
        ch = input[i];
    }

    while (!stk.isEmpty())
        str += stk.pop(); // add the rest of the stack into the string

    return str;
}

int  calcPostfix(string input)
{
    StackVector<int> stk = StackVector<int>(100);
    int i = 0;
    char ch = input[i];
    while (ch != '\0')
    {
    
        if (ch <= '9' && ch >= '0')
        {
            int j = i + 1;//THE NEXT CHAR 
            int num = ch - '0';
            while (input[j] != '\0' && input[j] <= '9' && input[j] >= '0') // THE NEXT IS A DIGIT
            {
                num = num * 10 + (input[j] - '0'); // add a digit to the number
                j++;
            }
            i = j - 1;
           
            stk.push(num);

        }
       
        if (ch == MULT || ch == DIV || ch == ADD || ch == SUB)
        {
            int num1, num2, num3=0;
            num2 = stk.pop();
            num1 = stk.pop();
            switch (ch)
            {
            case MULT:
            {
                num3 = num1 * num2;
                stk.push(num3);
            }break;
            case DIV:
            {
                num3 = num1 / num2;
                stk.push(num3);
            }break;
            case ADD:
            {
                num3 = num1 + num2;
                stk.push(num3);
            }break;
            case SUB:
            {
                num3 = num1 - num2;
                stk.push(num3);
            }break;
            
            }
        }
        i++;
        if (input[i] == ' ') //forward cause its a space
            i++;
        ch = input[i];
    }
    return stk.top(); // return the result
}