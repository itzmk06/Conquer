#include<iostream>
#include<stack>
using namespace std;

void findMiddle(stack<int>&st, int total_size){
    if(total_size==0){
        cout<<"Stack is empty!\n";
        return;
    }
    if(((total_size/2)+1)==st.size()){
        cout<<st.top()<<" is middle element!"<<endl;
        return;
    }
    int temp=st.top();
    st.pop();
    findMiddle(st,total_size);
    st.push(temp);

}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);

    int total_size=st.size();
    findMiddle(st,total_size);
    return 0;
}