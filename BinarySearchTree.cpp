#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

node* insertIntoBST(node* root, int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

bool searchInBST(node* root, int x){
    //Method 1:Recursion
    // if(root==NULL){
    //     return false;
    // }
    // if(root->data==x){
    //     return true;
    // }
    // if(root->data>x){
    //     return searchInBST(root->left,x);
    // }
    // else{
    //     return searchInBST(root->right,x);
    // }

    //Method 2:Iterative Method
    node* temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}

int minVal(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

node* maxVal(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node* deleteFromBST(node* root, int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        } 

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini= minVal(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }

    }
    else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

int main(){
    node* root=NULL;

    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);

    cout<<"Printing the BST:"<<endl;
    levelOrderTraversal(root);

    // cout<<"Printing Inorder:"<<endl;
    // inorder(root);

    // cout<<endl<<"Printing Preorder:"<<endl;
    // preorder(root);

    // cout<<endl<<"Printing Postorder:"<<endl;
    // postorder(root);

    // cout<<"Enter the number to be searched: "<<endl;
    // int x;
    // cin>>x;
    // if(searchInBST(root,x)){
    //     cout<<"Element Found"<<endl;
    // }
    // else{
    //     cout<<"Element not found"<<endl;
    // }

    // cout<<"Min: "<<minVal(root)<<endl;
    // cout<<"Max: "<<maxVal(root)->data<<endl;

    cout<<"Enter the number to be deleted: "<<endl;
    int val;
    cin>>val;
    root=deleteFromBST(root,val);
    cout<<"Printing the BST after deletion:"<<endl;
    levelOrderTraversal(root);

    return 0;
}