// Singly Circular
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;


    public:
        SinglyCL();
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
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node<T> * newn= NULL;

    newn = new struct node<T>;
    newn->data=no;
    newn->next=NULL;

    if((first==NULL) && (last==NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->next=first;
        first=newn;
    }
    last->next=first;
    Count++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node<T> * newn= NULL;

    newn = new struct node<T> ;
    newn->data=no;
    newn->next=NULL;

    if((first==NULL) && (last==NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        last->next=newn;
        last=newn;
        last->next=first;
    }
    last->next=first;
    Count++;
}

template <class T>
void SinglyCL<T>::Display()
{
    struct node<T> * temp=first;
    if((first != NULL) && (last != NULL))
    {
        do
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        } while (temp != last->next);
        
        cout<<"Address of First node\n";
    }
}

template <class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first==NULL) && (last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete(first);
        first=NULL;
        last=NULL;
    }
    else
    {
        first=first->next;
        free(last->next);
        last->next=first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct node<T> * temp=first;

    if((first==NULL) && (last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete(first);
        first=NULL;
        last=NULL;
    }
    else
    {
        while(temp->next != last)
        {
            temp = temp->next;
        }
        free(last);
        last=temp;
        last->next=first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no,int ipos)
{
    struct node<T> * newn = NULL;

    struct node<T> * temp=first;
    if((ipos<1) || (ipos> Count+1))
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
        newn = new struct node<T>;
        newn->data=no;
        newn->next=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        Count++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos<1) || (ipos> Count+1))
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
        struct node<T> * temp=first;
        int i=0;

        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        struct node<T> * Targetednod = temp->next;
        temp->next=temp->next->next;
        delete Targetednod;

        Count--;
    }
}

int main()
{
    SinglyCL<int> iobj;
    SinglyCL<float> fobj;
    SinglyCL<double> dobj;
    SinglyCL<char> cobj;

    int iRet=0;

    iobj.InsertFirst(111);
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    cout<<"Linked list of Integer:\n";
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n\n";

    iobj.InsertLast(121);
    iobj.InsertLast(151);

    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n\n";

    iobj.DeleteFirst();
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n\n";

    iobj.DeleteLast();
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n\n";

    iobj.InsertAtPos(181,4);
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n\n";

    iobj.DeleteAtPos(4);
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n\n";


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