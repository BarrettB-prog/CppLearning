#include <iostream>
using namespace std;

template <class T>
class List;

template <class T>
class Node
{
    friend class List<T>;
    
public:    
    Node();
    Node(T input);
    ~Node();
    
private:
    T data;
    Node<T> * nextptr;
};

template <class T>
Node<T>::Node()
{
    data = 0;
    nextptr = nullptr;
}

template <class T>
Node<T>::Node(T input)
{
    data = input;
    nextptr = nullptr;
}

template <class T>
Node<T>::~Node()
{
    nextptr = nullptr;
}


//----------------------------------
template <class T>
class List
{
    
public:
    List();
    ~List();
    
    void InsertFirst(T input);
    void InsertLast(T input);
    
    void RemoveFirst();
    void RemoveLast();
    
    void PrintList();
    
private:
    Node<T> * firstptr;
    Node<T> * lastptr;
};

template <class T>
List<T>::List()
{
    firstptr = nullptr;
    lastptr = nullptr;
}

template <class T>
List<T>::~List()
{
    firstptr = lastptr = nullptr;
}

template <class T>
void List<T>::InsertFirst(T input)
{
    if(firstptr == nullptr)
        firstptr = lastptr = new Node<T>(input);
    else
    {
        Node<T> * tempptr = new Node<T>(input);
        tempptr->nextptr = firstptr;
        firstptr = tempptr;
    }
}

template <class T>
void List<T>::InsertLast(T input)
{
    if(firstptr == nullptr)
        firstptr = lastptr = new Node<T>(input);
    else
    {
        Node<T> * tempptr = new Node<T>(input);
        lastptr->nextptr = tempptr;
        lastptr = tempptr;
    }
}

template <class T>
void List<T>::RemoveFirst()
{
    if(firstptr == nullptr)
        cout << "empty list";
    else if(firstptr == lastptr)
    {
        delete firstptr;
        firstptr = lastptr = nullptr;
    }
    else
    {
        Node<T> * tempptr = firstptr->nextptr;
        delete firstptr;
        firstptr = tempptr;
    }
}

template <class T>
void List<T>::RemoveLast()
{
    if(firstptr == nullptr)
        cout << "empty list";
    else if(firstptr == lastptr)
    {
        delete lastptr;
        firstptr = lastptr = nullptr;
    }
    else
    {
        Node<T> * tempptr = firstptr;
        
        while(tempptr->nextptr != lastptr)
            tempptr = tempptr->nextptr;
            
        delete lastptr;
        lastptr = tempptr;
    }
}

template <class T>
void List<T>::PrintList()
{
    Node<T> * tempptr = firstptr;
    
    while(tempptr != nullptr)
    {
        cout << tempptr->data;
        tempptr = tempptr->nextptr;
    }
    
}



int main()
{
    List<int> mylist;
    mylist.InsertFirst(1);
    mylist.InsertFirst(2);
    mylist.InsertFirst(3);
    mylist.PrintList();
    
    return 0;
}
