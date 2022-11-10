//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stacklnk.h"

//--------------------------------------------------------------------

template <class DT>
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr)
    :dataItem(nodeData) //dataItem = Null
    ,next(nextPtr)      //next=nullptr
{
 
}


//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int ignored)
    :top(0)//어떠한 Node도 가르키지 않은 top(0)  //top(NULL)
{
 
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    clear();
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
   /* if (!isFull())*/
    //Preconditions: Stack has been initialized and if not full
    // StackNode<DT>* location=new StackNode<DT>(newDataItem, top);
        
    //top->next = location; //head의 nextPtr이 다음 노드를 가르키게 함.
    // top = location;       //top을 새로만든 Node 자체를 가르키게 함.
    if (isFull())
    {
        cout << "Failed--Full stack" << endl;
    }
    else
    {
        StackNode<DT>* location;

        location = new StackNode<DT>(newDataItem, top);
        top = location;
    }
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    //temp이 top이 가리키는 것을 똑같이 가르키게 한 뒤
    //top을 이전 노드의 next로 옮기고 temp을 deallocate한다.
    if (isEmpty())
    {
        cout << "Failed--Llinked stack is already empty" << endl;
    }

    else
    {
        DT popData;
        StackNode<DT>* temp=top;
        top = top->next; //노드가 아닌 nextPtr을 가르키는게 문제가 될 것 같음
        popData = temp->dataItem;
        delete temp;
        return popData;
    }
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    StackNode<DT>* tempPtr;
    while (top != nullptr)
    {
        tempPtr = top;
        top = top->next;
        delete tempPtr;
    }
   
}
//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return (top == nullptr);
}
//--------------------------------------------------------------------


template <class DT>
bool Stack<DT>::isFull() const
{
    StackNode<DT>* location;

    location = new StackNode<DT>(NULL,nullptr);
    if (location == NULL)
        return true;
    else {
        delete location;
        return false;
    }

    return false;
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// Linked list implementation. Outputs the data items in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    StackNode<DT>* p;   // Iterates through the stack

    if (top == 0)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top ";
        for (p = top; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "bottom" << endl;
    }
}