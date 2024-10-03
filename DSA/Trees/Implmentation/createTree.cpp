#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

Node * createNode(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    
    // if data is 1 => i don't want to enter node no more 
    if(data==-1){
        return NULL;
    }
    
    // create root node 
    Node* root=new Node(data);
    
    // create left sub tree
    cout<<"\nfor left sub tree"<<data<<" :"<<endl;
    root->left=createNode();

    // create right sub tree
    cout<<"\nfor right sub tree"<<data<<" :"<<endl;
    root->right=createNode();

    return root;
}

void preOrder(Node* root){
    // base condition 
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    // push root node 
    q.push(root);
    // since we completed one level
    q.push(NULL); 
    while(!q.empty()){
        if(q.front()!=NULL){
            // take front node from queue and push it's left and right node 
            Node* frontElement=q.front();
            if(frontElement->left!=NULL){
                q.push(frontElement->left);
            }
            if(frontElement->right!=NULL){
                q.push(frontElement->right);
            }
            // print the front element and pop it off
            cout<<frontElement->data<<" ";
            q.pop();
        }else{
            // here we're sure that left and right childs are present in queue 
            cout<<endl;
            q.pop(); // remove the null we got 
            if(!q.empty()){
                q.push(NULL); // which acts as pointer for those child elements 
            }
        }
    }
}


int main(){
    Node* root=createNode();
    cout<<"\nRoot node is "<<root->data<<endl;

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}

// 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1 => input 
//  out put
// 1 2 4 5 3 6
// 4 2 5 1 3 6
// 4 5 2 6 3 1
// 1 2 3 4 5 6

