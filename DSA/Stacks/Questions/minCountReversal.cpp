//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    stack<char>st;
    if(s.length()%2!=0){
        return -1;
    }
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }else{
            if(!st.empty()&&st.top()=='{'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        char brace1=st.top();
        st.pop();
        char brace2=st.top();
        st.pop();
        if(brace1==brace2){
            count+=1;
        }else{
            count+=2;
        }
    }
    
    return count;
}