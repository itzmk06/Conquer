#include<iostream>
#include<stack>
using namespace std;
int main(){
    //* creating a stack 
    stack<int>st;
    
    //* inserting values into stack 
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    //* checking size of stack 
    cout<<endl<<"Size of stack is "<<st.size()<<endl;

    //* printing the elements of stack 
    cout<<"\nElements of stack are as follows:\n";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}