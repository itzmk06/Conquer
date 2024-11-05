class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // create heap which stores int and vector of int 
        priority_queue<pair<int,vector<int>>>q;
        // traverse though whole points
        for(auto point:points){
            int x=point[0];
            int y=point[1];
            // calculate x^2 + y^2 
            q.push({x*x+y*y,{x,y}});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<vector<int>>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};