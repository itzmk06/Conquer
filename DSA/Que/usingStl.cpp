#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;  // creation
    
    q.push(10);     // insertion 
    q.push(20);
    q.push(30);
    
    cout<<"Size of queue is "<<q.size();

    q.pop();        // removal


    // queue is empty or not 
    if(q.empty()){
        cout<<"\nqueue is empty!";
    }else{
        cout<<"\nqueue is not empty!";
    }

    // getting size of queue
    cout<<"\nsize of queue is "<<q.size();

    //  getting front element 
    cout<<"\nFront element of queue is "<<q.front();

    return 0;
}