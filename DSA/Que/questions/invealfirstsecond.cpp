#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int>q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    int n=q.size();
    int k=n/2;

    queue<int>q2;
    int count=0;
    while(count<k&&!q.empty()){
        int data=q.front();
        q.pop();
        q2.push(data);
        count++;
    }

    while(!q.empty()&&!q2.empty()){
        int first=q2.front();
        int second=q.front();
        q2.pop();
        q.pop();
        q.push(first);
        q.push(second);
    }

    if(n&1){
        int data=q.front();
        q.pop();
        q.push(data);
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }


    return 0;
}