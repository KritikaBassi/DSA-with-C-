# include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int value)
    {
        this->data=value;
        this->next=nullptr;
    }

    ~node()
    {
        int value=this->data;
        if (this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free"<<endl;
    }
};
 
void InsertAtHead(node* &head,int d)
{
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
void InsertAtTail(node* &tail,int d)
{
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}

void InsertAtPosition(node* &head,node* &tail,int d,int p)
{
    if(p==1)
    {
        InsertAtHead(head,d);
        return;
    }
    node* temp=head;
    int c=1;
    while(c<p-1)
    {
        temp=temp->next;
        c++;
    }
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
        return;
    }
    else
    {
        node* node2=new node(d);
        node2->next=temp->next;
        temp->next=node2;
    }
}

void deletenode(node* &head,node* &tail,int p)
{
    if(p==1)
    {
        node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        node* curr=head;
        node* prev=NULL;
        int c=1;
        while(c<p)
        {
            prev=curr;
            curr=curr->next;
            c++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        tail=prev->next;
    }
}

void printn(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node* node1=new node(10);

    node* head=node1;
    node* tail=node1;

    InsertAtHead(head,12);
    printn(head);

    InsertAtTail(tail,13);
    printn(head);

    InsertAtPosition(head,tail,20,3);
    printn(head);

    InsertAtPosition(head,tail,2,1);
    printn(head);

    InsertAtPosition(head,tail,5,6);
    printn(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    deletenode(head,tail,1);
    printn(head);

    deletenode(head,tail,5);
    printn(head);

    deletenode(head,tail,3);
    printn(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    return 0;
}