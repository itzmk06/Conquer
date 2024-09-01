#include<iostream>
#include<stack>
using namespace std;

stack<char>st;

int main(){
    string s="Manoj";
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    for(int i=0;i<s.length();i++){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
