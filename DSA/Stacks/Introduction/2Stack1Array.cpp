#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int * arr;
        int top1;
        int top2;
    public:
        Stack(int size){
            this->size=size;
            arr=new int[size];
            this->top1=-1;
            this->top2=size;
        }
        void push1(int data){
            if(top2-top1==1){
                cout<<"\nOverflow in stack1\n";
                return;
            }else{
                arr[++top1]=data;
                cout<<"\ndata inserted successfully!\n";
            }
        }
        void push2(int data){
            if(top2-top1==1){
                cout<<"\nOverflow in stack2\n";
                return;
            }else{
                arr[--top2]=data;
                cout<<"\ndata inserted successfully!\n";
            }
        }
        void pop1(){
            if(top1==-1){
                cout<<"\nStack1 is empty\n";
                return;
            }else{
                top1--;
                cout<<"\ndata deleted successfully!\n";
            }
        }
        void pop2(){
            if(top2==size){
                cout<<"\nStack2 is empty\n";
                return;
            }else{
                top2++;
                cout<<"\ndata deleted successfully!\n";
            }
        }
        void print(){
            for(int i=0;i<top2;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            for(int i=size-1;i>top1;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Stack s(10);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);
    s.push1(60);
    s.push2(100);
    s.push2(90);
    s.push2(80);
    s.push2(70);
    s.push2(60);
    s.print();

    return 0;
}