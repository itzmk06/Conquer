#include<bits/stdc++.h>
class Solution {
public:
    stack<int>st;
    int calPoints(vector<string>& operations) {
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                if(st.empty()){
                    continue;
                }else if(!st.empty()){
                    int n1=st.top();
                    int n2=0;
                    st.pop();
                    if(!st.empty()){
                        n2=st.top();
                    }
                    int result=n1+n2;
                    st.push(n1);
                    st.push(result);
                }
            }else if(operations[i]=="D"){
                    if(!st.empty()){
                        int val=st.top();
                        int result=2*val;
                        st.push(result);
                    }else{
                        continue;
                    }
                }else if(operations[i]=="C"){
                    if(!st.empty()){
                        st.pop();
                    }else{
                        continue;
                    }
                }else{
                    st.push(stoi(operations[i]));
                }
        }
        int sum=0;
        while(!st.empty()){
            int val=st.top();
            st.pop();
            sum+=val;
        }
        return sum;
    }
};