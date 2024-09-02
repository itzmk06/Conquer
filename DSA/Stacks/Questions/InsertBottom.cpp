#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int>&st,int target){
    if(st.empty()){
        st.push(target);
        return;
    }
    int temp=st.top();
    st.pop();
    solve(st,target);
    st.push(temp);
}

void removeTopElement(stack<int>&st){
    if(!st.empty()){
        int target=st.top();
        st.pop();
        solve(st,target);
    }else{
        cout<<"stack is empty!"<<endl;
    }
}

void print(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    print(st);
    removeTopElement(st);
    print(st);


    return 0;
}