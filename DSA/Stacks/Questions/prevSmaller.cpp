#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int>ans(v.size());

    stack<int>s;
    s.push(-1);

    for(int i=0;i<v.size();i++){
        int curr=v[i];
        
        while(s.top()>=curr){
            s.pop();
        }

        ans[i]=s.top();
        s.push(curr);
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}