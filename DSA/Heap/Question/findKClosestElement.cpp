class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>q;
        for(int num:arr){
            q.push({abs(num-x),num});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int element=q.top().second;
            q.pop();
            ans.push_back(element);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};