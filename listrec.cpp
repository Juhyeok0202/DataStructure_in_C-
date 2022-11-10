//--------------------------------------------------------------------
//
//  Laboratory 10                                         listrec.cpp
//
//  Partial linked list implementation of the List ADT with
//  additional recursive linked list functions
//
//--------------------------------------------------------------------

#include "listrec.h"
#include "stacklnk.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Insert your singly linked list implementations (from Laboratory 7)
// of the following functions:
//
//   - The ListNode class constructor
//
//   - The List class constructor, destructor, insert(), clear(), and
//     showstructure() functions. You may also need to add isEmpty()
//     isFull(), and others.
//
//--------------------------------------------------------------------
template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}

template<class DT>
List<DT>::List(int ignored)
{
    head = 0;
    cursor = 0;
}

template<class DT>
List<DT>::~List()
{
    //clear();
}

template<class DT>
void List<DT>::insert(const DT& newData)
{
    ListNode<DT>* newNode = new ListNode<DT>(newData, nullptr);

    if (head == nullptr)
    {//first
        head = newNode;
        cursor = newNode;
    }
    else if (cursor->next == nullptr)
    {//end of
        cursor->next = newNode;
        cursor = newNode;
    }
    else
    {//middle
        newNode->next = cursor->next;
        cursor->next = newNode;
        cursor = newNode;
        
    }
}

template<class DT>
void List<DT>::clear()
{
    ListNode<DT>* tempNode = head;
    while (head != nullptr)
    {
        head = head->next;
        delete tempNode;
    }
}

template<class DT>
void List<DT>::showStructure() const
{
    if (head == nullptr)
        cout << "Empty list" << endl;
    else
    {
        for (ListNode<DT>* p = head; p != nullptr; p = p->next)
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
        cout << endl;
    }
}


//--------------------------------------------------------------------
//
// Recursively implemented linked list functions used in the Prelab
// Exercise
//
//--------------------------------------------------------------------

template < class DT >
void List<DT>:: write () const

// Outputs the data in a list from beginning to end. Assumes that
// objects of type DT can be output to the cout stream.

{
    cout << "List : ";
    writeSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeSub ( ListNode<DT> *p ) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
    if ( p != 0 )
    {
       cout << p->dataItem;      // Output data
       writeSub(p->next);    // Continue with next node
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insertEnd ( const DT &newDataItem )

// Inserts newDataItem at the end of a list. Moves the cursor to
// newDataItem.

{
    insertEndSub(head,newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: insertEndSub ( ListNode<DT> *&p,
                               const DT &newDataItem )

// Recursive partner of the insertEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if ( p != 0 )
       insertEndSub(p->next,newDataItem);    // Continue searching for
    else                                     // end of list
    {
       p = new ListNode<DT>(newDataItem,0);  // Insert new node
       cursor = p;                           // Move cursor
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: writeMirror () const

// Outputs the data in a list from beginning to end and back
// again. Assumes that objects of type DT can be output to the cout
// stream.

{
    cout << "Mirror : ";
    writeMirrorSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeMirrorSub ( ListNode<DT> *p ) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if ( p != 0 )
    {
       cout << p->dataItem;           // Output data (forward)
       writeMirrorSub(p->next);   // Continue with next node
       cout << p->dataItem;           // Output data (backward)
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: reverse ()

// Reverses the order of the data items in a list.

{
    reverseSub(0,head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: reverseSub ( ListNode<DT> *p, ListNode<DT> *nextP )

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{
    if ( nextP != 0 )
    {
       reverseSub(nextP,nextP->next);   // Continue with next node
       nextP->next = p;                 // Reverse link
    }
    else
       head = p;                        // Move head to end of list
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: deleteEnd ()

// Deletes the data at the end of a list. Moves the cursor to the
// beginning of the list.

{
    deleteEndSub(head);
    cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: deleteEndSub ( ListNode<DT> *&p )

// Recursive partner of the deleteEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if ( p->next != 0 )
       deleteEndSub(p->next);   // Continue looking for the last node
    else
    {
       delete p;                // Delete node
       p = 0;                   // Set p (link or head) to null
    }
}

//--------------------------------------------------------------------

template < class DT >
int List<DT>:: getLength () const

// Returns the number of data items in a list.

{
    return getLengthSub(head);

  
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
int List<DT>:: getLengthSub ( ListNode<DT> *p ) const

// Recursive partner of the length() function. Processes the sublist
// that begins with the node pointed to by p.

{
    int result;   // Result returned

    if ( p == 0 )
       result = 0;                            // End of list reached
    else
       result = (getLengthSub(p->next) + 1 );   // Number of nodes after
                                              // this one + 1
    return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::iterReverse()
{   
    ListNode<DT>* nextP = head;
    ListNode<DT>* p = 0;
    ListNode<DT>* tempP;
    while (nextP != nullptr)
    {
        tempP = nextP->next;
        nextP->next = p;
        p = nextP;
        nextP = tempP;

        if (nextP == nullptr)
        {
            head = p;
        }
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::stackWriteMirror() const
{
    //st과 반복문이용
    //if (p != 0)
    //{
    //    cout << p->dataItem;           // Output data (forward)
    //    writeMirrorSub(p->next);   // Continue with next node
    //    cout << p->dataItem;           // Output data (backward)
    //}
    Stack<DT> st;
    ListNode<DT>* tempNode=head;
    while (tempNode!=nullptr)
    {
        cout << tempNode->dataItem;
        st.push(tempNode->dataItem);

        tempNode = tempNode->next;
    }
    while (st.isEmpty() == false)
    {
        cout << st.pop();
    }
    cout << endl;

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::aBeforeb()
{
    aBeforebSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::aBeforebSub(ListNode<DT> *&p)
{
    //b가 나오면 그 이전에 a를 삽입.
    /*if(p->next == nullptr)*/
    if (p != 0)
    {
        aBeforebSub(p->next);
        if (p->dataItem == 'b')
        {
            p = new ListNode<DT>('a', p);
        }
    }
}