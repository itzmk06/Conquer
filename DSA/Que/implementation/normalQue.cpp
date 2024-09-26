#include<iostream>
using namespace std;

class Que{
    public:
        
        int rear;
        int front;
        int size;
        int * arr;

        // constructing que
        Que(int size){
            this->size=size;
            arr=new int[size];
            front=0;
            rear=0;
        }

        // inserting an item into queue 
        void push(int value){
            // check whether que is full or not 
            if(rear==size){
                cout<<"\nQue is full!";
            }else{
                arr[rear]=value;
                rear++;
            }
        }

        // removing an item from queue 
        void pop(){
            // check whether que is empty
            if(front==rear){
                cout<<"\nQueue is empty!";
            }else{
                front++;
                if(front==rear){
                    front=rear=0;
                }
            }
        }

        // get getSize of que
        int getSize(){
            // check que is empty 
            if(front==rear){
                cout<<"\nQue is empty!";
                return 0;
            }else{
                return rear-front;
            }
        }

        // check whether que is empty or not 
        bool isEmpty(){
            if(front==rear){
                return true;
            }else{
                return false;
            }
        }

        int getFront(){
            // check whether que is empty 
            if(front==rear){
                cout<<"\nQue is empty";
                return -1;
            }else{
                return arr[front];
            }
        }
};

int main(){
    Que q(5);
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    // cout<<q.push(60)<<endl;
    
    cout<<"\nfront :"<<q.getFront();

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;


    return 0;
}

// * 40:00

