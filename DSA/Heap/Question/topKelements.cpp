class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>q;
        for(int num:nums){
            q[num]++;
        }
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>h;
        for(auto i=q.begin();i!=q.end();i++){
            h.push({i->second,i->first});
            if(h.size()>k){
                h.pop();
            }
        }
        while(!h.empty()){
            int element=h.top().second;
            h.pop();
            ans.push_back(element);
        }
        return ans;
    }
};