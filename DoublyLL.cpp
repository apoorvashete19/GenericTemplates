// Doubly Linear
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    Count = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn=new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(first== NULL)
    {
        first=newn;    }
    else
    {
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    Count++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    newn=new struct node<T>;

    struct node<T> * temp=first;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(first== NULL)
    {
        first=newn;    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
        
    }
    Count++;
}

template <class T>
void DoublyLL<T>::Display()
{
    printf("NULL<=>");
    struct node<T> * temp = first;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp=temp->next;
    }
    cout<<"NULL \n\n";
}

template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct node<T> * temp = first;
    if(first==NULL)
    {
        return;
    }
    else if((first->next==NULL) && (first->prev==NULL))
    {
        delete first;
        first=NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;

    }
    Count--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> * temp=first;

    if(first==NULL)
    {
        return;
    }
    else if((first->next==NULL) && (first->prev==NULL))
    {
        delete first;
        first=NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }
        delete (temp->next);
        temp->next=NULL;
    }
    Count--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) && (ipos>Count+1))
    {
        return;
    }
    else if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn=NULL;
        struct node<T> * temp = first;

        newn = new struct node<T>;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
        Count++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) && (ipos>Count))
    {
        return;
    }
    else if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = first;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        Count--;
    }
}

int main()
{
    DoublyLL<int> obj;
    DoublyLL<float> fobj;
    DoublyLL<double> dobj;
    DoublyLL<char> cobj;
    int iRet=0;

    obj.InsertFirst(111);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    iRet=obj.CountNode();
    cout<<"Number of elements in a linked list is:"<<iRet<<"\n\n";

    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.Display();

    iRet=obj.CountNode();
    cout<<"Number of elements in a linked list is:"<<iRet<<"\n\n";

    obj.InsertAtPos(105,5);
    obj.Display();

    iRet=obj.CountNode();
    cout<<"Number of elements in a linked list is:"<<iRet<<"\n\n";

    obj.DeleteAtPos(5);
    obj.Display();

    iRet=obj.CountNode();
    cout<<"Number of elements in a linked list is:"<<iRet<<"\n\n";


    obj.DeleteFirst();
    obj.Display();

    iRet=obj.CountNode();
    cout<<"Number of elements in a linked list is:"<<iRet<<"\n\n";

    obj.DeleteLast();
    obj.Display();

    iRet=obj.CountNode();
    cout<<"Number of elements in a linked list is:"<<iRet<<"\n\n";

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    cout<<"Linked list of floats:\n";
    fobj.Display();

    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9999);

    cout<<"Linked list of Doubles:\n";
    dobj.Display();

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    cout<<"Linked list of Characters:\n";
    cobj.Display();

    
    return 0;
}