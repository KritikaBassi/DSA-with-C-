# include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void insertNode(node* &tail,int n,int d){
    node *temp=new node(d);

    //Empty list
    if(tail==NULL){
        tail=temp;
        temp->next=temp;
    }
    else{
        node *curr=tail;
        while(curr->data!=n){
            curr=curr->next;
        }
        
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deleteNode(node* &tail,int n){
    if(tail==NULL){
        cout<<"Empty"<<endl;
    }
    else{
        node *prev=tail;
        node *curr=prev->next;

        while(curr->data!=n){
            prev=curr;
            curr=curr->next;
        }
        //single element in LL
        if(prev==curr){
            tail=NULL;
        }
        //2 elements in LL
        else if(tail==curr){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void printl(node* &tail){
    if(tail==NULL){
        cout<<"Empty"<<endl;
        return;
    }
    node *temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=tail);
    cout<<endl;
}

int main(){
    node* tail=NULL;

    insertNode(tail,5,3);
    printl(tail);
    // insertNode(tail,3,5);
    // printl(tail);
    // insertNode(tail,5,7);
    // printl(tail); 
    // insertNode(tail,7,9);
    // printl(tail); 
    // insertNode(tail,5,6);
    // printl(tail); 
    // insertNode(tail,9,10);
    // printl(tail); 
    // insertNode(tail,3,4);
    // printl(tail); 

    deleteNode(tail,3);
    printl(tail);

    return 0;
}