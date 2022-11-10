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
    :top(0)//��� Node�� ����Ű�� ���� top(0)  //top(NULL)
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
        
    //top->next = location; //head�� nextPtr�� ���� ��带 ����Ű�� ��.
    // top = location;       //top�� ���θ��� Node ��ü�� ����Ű�� ��.
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
    //temp�� top�� ����Ű�� ���� �Ȱ��� ����Ű�� �� ��
    //top�� ���� ����� next�� �ű�� temp�� deallocate�Ѵ�.
    if (isEmpty())
    {
        cout << "Failed--Llinked stack is already empty" << endl;
    }

    else
    {
        DT popData;
        StackNode<DT>* temp=top;
        top = top->next; //��尡 �ƴ� nextPtr�� ����Ű�°� ������ �� �� ����
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