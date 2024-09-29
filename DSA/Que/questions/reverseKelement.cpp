// * Reverse first k elements from queue 
#include<bits/stdc++.h>
using namespace std;

int main(){
    // create a queue 
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);


    // create a stack 
    stack<int>st;

    // get size 
    int n=q.size();
    int k=3;

    // edge case  
    if(k==0||k>n||k==1){
        return 0;
    }

    // keep a counter 
    int count=0;

    // push k elements into stack 
    while(!q.empty()&&count<k){
        int data=q.front();
        q.pop();
        st.push(data);
        count++;
    }

    // pop elements from stack and push it into queue 
    while(!st.empty()){
        int data=st.top();
        st.pop();
        q.push(data);
    }

    // pop and push remaining n-k elements into queue from queue 
    int remaining=n-k;
    int count1=0;
    while((count1<remaining)){
        int data=q.front();
        q.pop();
        q.push(data);
        count1++;
    }

    // print queue elements
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
