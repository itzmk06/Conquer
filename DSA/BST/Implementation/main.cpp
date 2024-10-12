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

Node* insertIntoBst(Node* root,int data){
    // handle if this is the first node 
    if(root==NULL){
        Node* newNode=new Node(data);
        return newNode;
    }
    // handle if tree is not empty 
    if(data>root->data){
        root->right=insertIntoBst(root->right,data);
    }else{
        root->left=insertIntoBst(root->left,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cout<<"Enter data:";
    cin>>data;
    // while data==-1 it means we need to stop 
    while(data!=-1){
        // create a node and insert 
        root=insertIntoBst(root,data);
        // take input 
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    // insert root node into q
    q.push(root);
    // perform actions as long as q is not empty 
        int size=q.size();
    while(!q.empty()){
        // take out front element from queue 
        Node* front=q.front();
        // pop the front element 
        q.pop();
        // process the front element 
        cout<<front->data<<" ";
        // insert left and right if present of front element into queue 
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
        size--;
        if(size==0){
            cout<<endl;
            size=q.size();
        }
    }
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

bool searchInBst(Node* root,int target){
    // if tree is empty
    if(root==NULL){
        return false;
    }
    // if current node is equal to target
    if(target==root->data){
        return true;
    }
    bool rightAns=false;
    bool leftAns=false;
    // check target is > current node 
    if(target>root->data){
        //  go to right 
        rightAns=searchInBst(root->right,target);
    }else{
        // go ro left 
        leftAns=searchInBst(root->left,target);
    }
    return leftAns||rightAns;
}

int minValue(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

int maxValue(Node* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}

int getInOrderSuccessor(Node* root,Node* &successor,int data){
    if(root==NULL){
        return -1;
    }
    // now find that current node 
    if(root->data==data){
        // now i will perform actions 
        // check whether current node has right sub tree 
        if(root->right!=NULL){
            // move to right 
            root=root->right;
            // now if left sub tree is present go deep 
            // since we needed smallest from left
            while(root->left!=NULL){
                root=root->left;
            }
            // now return root->data 
            return root->data;
        }else{
            if(successor!=NULL){
                return successor->data;
            }else{
                return -1;
            }
        }
    }else if(data>root->data){
        // move right
        return getInOrderSuccessor(root->right,successor,data);
    }else{
        // move left 
        successor=root;
        return getInOrderSuccessor(root->left,successor,data);
    }
    //  it you didn't get anything 
    return -1;
}

int getInOrderPredessor(Node* root,Node* &predessor,int data){
    if(root==NULL){
        return -1;
    }
    if(root->data==data){
        // now i will perform some operations
        // go to left if present 
        if(root->left!=NULL){
            root=root->left;
            // now move to right to get highest element from right 
            while(root->right!=NULL){
                root=root->right;
            }
            // now return the data 
            return root->data;
        }else{
            // in order predessor doesn't exist 
            if(predessor!=NULL){
                return predessor->data;
            }else{
                return -1;
            }
        }
    }
    // check whether to go to right or to left 
    else if(data>root->data){
        // go to right and then search 
        predessor=root;
        return getInOrderPredessor(root->right,predessor,data);
    }else{
        // go to left and then search 
        return getInOrderPredessor(root->left,predessor
        ,data);
    }
    return -1;
}

int main(){
    Node* root=NULL;
    // take input
    takeInput(root);
    cout<<"\nPrinting level order:\n";
    levelOrderTraversal(root);
    cout<<"\nPrinting pre order:\n";
    preOrder(root);
    cout<<"\nPrinting post order:\n";
    postOrder(root);
    cout<<"\nPrinting in order:\n";
    inOrder(root);
    cout<<endl;
    cout<<searchInBst(root,20)<<endl;
    cout<<searchInBst(root,5)<<endl;
    cout<<searchInBst(root,500)<<endl;
    cout<<"Min value in bst is "<<minValue(root);
    cout<<endl;
    cout<<"Max value in bst is "<<maxValue(root);
    cout<<endl;
    Node* predessor=NULL;
    cout<<"Inorder predessor of 20 is "<<getInOrderPredessor(root,predessor,20)<<endl;
    cout<<"Inorder predessor of 10 is "<<getInOrderPredessor(root,predessor,10)<<endl;
    cout<<"Inorder predessor of 11 is "<<getInOrderPredessor(root,predessor,11)<<endl;
    cout<<"Inorder predessor of 8 is "<<getInOrderPredessor(root,predessor,8)<<endl;
    cout<<"Inorder predessor of 5 is "<<getInOrderPredessor(root,predessor,5)<<endl;
    cout<<endl;
    Node* successor=NULL;
    cout<<"Inorder successor of 20 is "<<getInOrderSuccessor(root,successor,20)<<endl;
    cout<<"Inorder successor of 10 is "<<getInOrderSuccessor(root,successor,10)<<endl;
    cout<<"Inorder successor of 11 is "<<getInOrderSuccessor(root,successor,11)<<endl;
    cout<<"Inorder successor of 8 is "<<getInOrderSuccessor(root,successor,8)<<endl;
    cout<<"Inorder successor of 5 is "<<getInOrderSuccessor(root,successor,5)<<endl;
    cout<<endl;

    return 0;
}

// 10 20 5 11 17 2 4 8 6 25 15 -1