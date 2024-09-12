#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;
    vector<int>v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);

    vector<int>ans(v.size());
    s.push(-1);

    // traversing from right to left 
    for(int i=v.size()-1;i>=0;i--){
        // get current element 
        int curr=v[i];
        
        // until you get smallest element in stack pop it off
        while(s.top()>=curr){
            s.pop();
        }

        // now you should have smallest element 
        ans[i]=s.top();

        // now push the curr element to stack 
        s.push(curr);
    }

    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}