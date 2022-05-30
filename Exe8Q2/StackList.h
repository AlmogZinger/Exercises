#include "List.h"	//page 18
#include "Stack.h"	//page 18
//-------------------------------------------------------
//  class StackList
//  Stack implemented using List operations
//-------------------------------------------------------

class StackList : public Stack
{
public:
    // constructors
    StackList();
    StackList(const StackList& s);

    // Stack operations
    void clear() ;
    bool isEmpty() const ;
    int pop() ;
    void push(int value);
    int top() const ;
protected:
    // data fields
    List data;
};