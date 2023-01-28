#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    Node * head;

public:
    // int length=0;

    LinkedList(){
        head = NULL;
    }

    void insertNodeAtEnd(int);
    void insertNodeAtFirst(int);
    void printLinkedList();
    int getLengthOfList();
    void numberToList(int x);
    void reverseList();
    void Addition(LinkedList l1, LinkedList l2, int size_n1, int size_n2);
};

int LinkedList :: getLengthOfList(){
    Node * ptr = head;
    int length = 0;
    
    while (ptr != NULL){
        ptr = ptr->next;
        length++;
    }
    return length;
}

void LinkedList::insertNodeAtEnd(int data){
    Node * newNode = new Node(data);
    
    if(head == NULL){
        head = newNode;
        return;
    }
    else{
        Node * ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=newNode;
    }
}

void LinkedList::insertNodeAtFirst(int data){
    Node * newNode = new Node(data);
    
    if(head == NULL){
        head = newNode;
        return;
    }
    else{
        Node * ptr = head;
        newNode->next = ptr;
        head = newNode;
    }
}

void LinkedList :: printLinkedList(){
    Node * ptr = head;
    
    if (head == NULL){
        cout << "List is empty" <<  endl;
        return;    
    }
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}


void LinkedList :: numberToList(int x){
    int temp;
    while(x){
        int temp = x % 10;
        insertNodeAtEnd(temp);   
        // insertNodeAtFirst(temp);   
        x=x/10;
    }
}

void LinkedList :: reverseList(){
    Node * current = head;
    Node * previous = NULL;
    Node * next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous; 
}

void LinkedList :: Addition(LinkedList l1, LinkedList l2, int size_n1, int size_n2){
    
    Node * temp1 = l1.head;
    Node * temp2 = l2.head;
    int t1_max=0, t2_max=0;
    int carry=0;

    if (size_n1>size_n2){
        t1_max=1;
    }else{
        t2_max=1;
    }

    while (temp1 != NULL && temp2 != NULL){
        int fin = temp1->data + temp2->data + carry;
        insertNodeAtEnd(fin%10);
        carry=fin/10;
        temp1=temp1->next;
        temp2=temp2->next; 
    }

    if (size_n1 != size_n2){
        Node * temp3;
        if (t1_max){
            temp3 = temp1;
        }
        else{
            temp3 = temp2;
        }

        while (temp3 != NULL)
        {
            int fin2 = temp3->data + carry;
            insertNodeAtEnd(fin2%10);
            carry=fin2/10;
            temp3=temp3->next;
        }
    }
    
    if (carry != 0){
        insertNodeAtEnd(carry);
    }
}

int main(){
    system("cls");

    int a, b, size_n1=0, size_n2=0;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    LinkedList l1, l2, l3;

    l1.numberToList(a);
    l2.numberToList(b);

    size_n1 = l1.getLengthOfList();
    size_n2 = l2.getLengthOfList();
    // cout << "\n\n" << size_n1 << " " << size_n2 << endl;

    cout << "\n\nElements of the linked-list-1 are: ";
    l1.printLinkedList();
    cout << "\nElements of the linked-list-2 are: ";
    l2.printLinkedList(); 

    l3.Addition(l1, l2, size_n1, size_n2);
    
    cout << "\n\nThe addition of two numbers using Linked List is: ";
    l3.reverseList();
    l3.printLinkedList();
    cout << "\n\n";
    
    return 0;
}