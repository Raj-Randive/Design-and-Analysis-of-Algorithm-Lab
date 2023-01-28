#include <iostream>
#include <windows.h>
using namespace std;

class node{
public:
    int data;
    node * next;
    node()
    {
        data=0;
        next=NULL;
    }
    node(int data)
    {
        data=data;
        next=NULL;
    }
};

void Insertion(node* &head, int data)
{
    node * temp = new node(data);

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node* temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

void ReverseLL(node* &head)
{
    node* current = head;
    node *prev = NULL, *next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void displayLinkedList(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
}

void NumberToLL(node* &head,int n,int &size)
{
    while(n)
    {
        Insertion(head,n%10);
        n=n/10;
        size++;
    }
}

void Addition(node* &head1,int size_n1,node* &head2,int size_n2,node* &add)
{
    node* temp1=head1;
    node* temp2=head2;

    int t1_max=0,t2_max=0;
    int carry=0;

    if(size_n1>size_n2)
    {
        t1_max=1;
    }
    else
    {
        t2_max=1;
    }
    
    while(temp1!=NULL && temp2!=NULL)
    {
        int fin=temp1->data + temp2->data + carry;
        Insertion(add,fin%10);
        carry=fin/10;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    if(size_n1!=size_n2)
    {
        node* temp3;
        if(t1_max)
        {
            temp3=temp1;
        }
        else
        {
            temp3=temp2;
        }
        while(temp3!=NULL)
        {
            int fin2=temp3->data+carry;
            Insertion(add,fin2%10);
            carry=fin2/10;
            temp3=temp3->next;
        }
    }
    
    if(carry)
    {
        Insertion(add,carry);
    }
    ReverseLL(add);
}

void Subtraction(node* &head1,int size_n1,node* &head2,int size_n2,node* &sub)
{
    
}

int main()
{
    system("cls");
    node * head1=NULL;
    node * head2=NULL;

    node * add=NULL;
    node * sub=NULL;
    node * mul=NULL;
    int n1,n2,size_n1=0,size_n2=0;
    
    cout<<"Enter first number: ";
    cin>>n1;
    cout<<"Enter second number: ";
    cin>>n2;
    
    NumberToLL(head1,n1,size_n1);
    NumberToLL(head2,n2,size_n2);
    Addition(head1,size_n1,head2,size_n2,add);
    
    Sleep(1000);
    
    cout<<"Addition of "<<n1<<" and "<<n2<<": ";
    displayLinkedList(add);

    system("pause");
    
    return 0;
}