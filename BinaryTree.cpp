#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}

void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// void reverselevelOrderTraversal(node* root){
//     stack<node*> s;
//     s.push(root);
//     s.push(NULL);

//     while(!s.empty()){
//         node *temp=s.top();
//         s.pop();

//         if(temp==NULL){
//             cout<<endl;
//             if(!s.empty()){
//                 s.push(NULL);
//             }
//         }
//         else{
//             cout<<temp->data<<" ";
//             if(temp->left){
//                 s.push(temp->left);
//             }
//             if(temp->right){
//                 s.push(temp->right);
//             }
//         }
//     }
// }

void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFormLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

void trav(node* root,int &c){
    if(root==NULL){
        return ;
    }
    trav(root->left,c);
    
    if(root->left==NULL && root->right==NULL){
        c++;
    }
    trav(root->right,c);
}

int noOfLeafNodes(node* root){
    int c=0;
    trav(root,c);
    return c;
}

int main()
{
    node *root=NULL;
    //root=buildTree(root);

    buildFormLevelOrder(root);

    // cout<<"Printing the level order traversal output: "<<endl;
    //levelOrderTraversal(root);

    //cout<<"Printing the reverse level order traversal output: "<<endl;
    //reverselevelOrderTraversal(root);

    // cout<<endl<<"Inorder: "<<endl;
    // inorder(root);

    // cout<<endl<<"Preorder: "<<endl;
    // preorder(root);

    // cout<<endl<<"Postorder: "<<endl;
    // postorder(root);
    
    cout<<noOfLeafNodes(root)<<endl;

    return 0;
}