//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        stack<int>st;
        int celebIndex=-1;
        
        // push the persons into stack 
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        
        // discard the persons 
        while(st.size()!=1){
            // take the first two elements 
            int a=st.top(); 
            st.pop();
            int b=st.top();
            st.pop();
            
            // check who knows who 
            if(mat[a][b]){
                // a knows b means a is not celeb
                st.push(b);
            }else{
                // b is not celeb 
                st.push(a);
            }
        }
        
        
        if(st.size()==1){
             celebIndex=st.top();
            st.pop();
        }
        
        // check whether celeb don't know anyone 
        for(int i=0;i<mat.size();i++){
            if(mat[celebIndex][i]==1){
                return -1;
            }
        }
        
        // check whether everyone knows celeb 
        for(int i=0;i<mat.size();i++){
            if(mat[i][celebIndex]==0&&i!=celebIndex){
                return -1;
            }
        }
        
        // he's our celeb return it's index
        return celebIndex;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends