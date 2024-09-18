#include<bits/stdc++.h>
class Solution {
public:
vector<int> findNextSmaller(vector<int> h){
        stack<int>st;
        st.push(-1);
        vector<int>ans(h.size());
        for(int i=h.size()-1;i>=0;i--){
            int curr=h[i];
            while(st.top()!=-1&&h[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findPrevSmaller(vector<int>h){
        stack<int>st;
        vector<int>ans(h.size());
        st.push(-1);
        for(int i=0;i<h.size();i++){
            int curr=h[i];
            while(st.top()!=-1&&h[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& h) {
        vector<int>prev=findPrevSmaller(h);
        vector<int>next=findNextSmaller(h);
        int maxArea=INT_MIN;
        for(int i=0;i<h.size();i++){
            if(next[i]==-1){
                next[i]=h.size();
            }
            int w=next[i]-prev[i]-1;
            int area=h[i]*w;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }else{
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};