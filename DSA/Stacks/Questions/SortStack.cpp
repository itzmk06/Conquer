#include<iostream>
#include<stack>
using namespace std;



void insertSorted(stack<int>&st,int target){
    if(st.empty()){
        st.push(target);
        return;
    }
    if(st.top()<=target){
        st.push(target);
        return;
    }
    int temp=st.top();
    st.pop();
    insertSorted(st,target);
    st.push(temp);
}

void sort(stack<int>&st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    sort(st);
    insertSorted(st,temp);
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
    st.push(40);
    st.push(20);
    st.push(70);
    st.push(10);
    print(st);
    sort(st);
    print(st);



    return 0;
}


// 20:58