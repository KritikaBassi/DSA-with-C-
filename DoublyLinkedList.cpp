#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }

    ~node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        //cout<<"Memory free for node with data "<<val<<endl;
    }
};

void printnode(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int lengthnode(node* &head)
{
    int len=0;
    node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    cout<<endl;
    return len;
}

void InsertAtHead(node* &head,node* &tail,int x){
    if(head==NULL){
        node* temp=new node(x);
        head=temp;
        tail=temp;
    }
    else{
        node* temp=new node(x);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    
}

void InsertAtTail(node* &head,node* &tail,int x){
    if(tail==NULL){
        node* temp=new node(x);
        head=temp;
        tail=temp;
    }
    else{
        node* temp=new node(x);
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

void InsertAtPos(node* &head,node* &tail,int x,int p)
{
    node* newnode=new node(x);
    node* temp=head;
    if(p==1)
    {
        InsertAtHead(head,tail,x);
        return;   
    }
    else
    {
        int c=1;
        while(c<p-1){
            temp=temp->next;
            c++;
        }
        if(temp->next==NULL)
        {
            InsertAtTail(head,tail,x);
            return;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void deleteNode(node* &head,node* &tail,int p){
    node* temp=head;
    if(p==1){
        if(head==NULL){
            cout<<"Linked list is Empty"<<endl;
            return;
        }
        else{
            temp->next->prev=NULL;
            head=temp->next;
            temp->next=NULL;
        }
    }
    else{
        int c=1;
        while(c!=p){
            temp=temp->next;
            c++;
        }
        if(temp->next==NULL){
            temp->prev->next=NULL;
            tail=temp->prev;
            temp->prev=NULL;
        }
        else{
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            temp->next=NULL;
            temp->prev=NULL;
        }

    }
    delete temp;
}

int main()
{
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    printnode(head);
    //cout<<lengthnode(head);

    InsertAtHead(head,tail,11);
    printnode(head);

    InsertAtHead(head,tail,13);
    printnode(head);

    InsertAtHead(head,tail,14);
    printnode(head);

    InsertAtTail(head,tail,12);
    printnode(head);

    InsertAtPos(head,tail,2,3);
    printnode(head);
    cout<<"Head= "<<head->data<<endl;
    cout<<"Tail= "<<tail->data<<endl;
    
    deleteNode(head,tail,6);
    printnode(head);
    cout<<"Head= "<<head->data<<endl;
    cout<<"Tail= "<<tail->data<<endl;

    return 0;
}