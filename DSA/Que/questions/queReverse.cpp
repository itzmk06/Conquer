// * using stack 

// #include<iostream>
// #include<queue>
// #include<stack>
// using namespace std;

// int main(){
//     queue<int>q;
//     stack<int>st;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);
//     q.push(50);
//     q.push(60);
//     while(!q.empty()){
//         int data=q.front();
//         st.push(data);
//         q.pop();
//     }
//     while(!st.empty()){
//         int data=st.top();
//         st.pop();
//         q.push(data);
//     }
//     while(!q.empty()){
//         cout<<q.front()<<" ";
//         q.pop();
//     }

//     return 0;
// }

//* using recursion 

#include<iostream>
#include<queue>
using namespace std;


void reverseQue(queue<int>&q){
    // base case
    if(q.empty()){
        return;
    }
    // take front element 
    int temp=q.front();
    q.pop();
    reverseQue(q);
    q.push(temp);
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseQue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}


