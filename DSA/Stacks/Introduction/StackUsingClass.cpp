#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int* arr;
        int top;
    public:
        Stack(int size){
            this->size=size;
            this->arr=new int[size];
            this->top=-1;
        }
        
    void push(int data){
    if(size-top<=1){
        cout<<"\nStack Overflow!\n";
        return;
    }else{
        arr[top++]=data;
        cout<<"\nInserted "<<data<<" successfully!\n";
        return;
    }
}

void pop(){
    if(top==-1){
        cout<<"\nStack underflow!\n";
        return;
    }else{
        top--;
    }
}

int getTop(){
    if(top==-1){
        cout<<"\nStack is empty!\n";
    }else{
        return arr[top-1];
    }
}

int getSize(){
    return top+1;
}

bool isEmpty(){
    if(top==-1){
        return true;
    }else{
        return false;
    }
}

};



int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    s.push(110);
    s.push(120);

    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
    s.pop();


    return 0;
}
