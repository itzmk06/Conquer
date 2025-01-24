// * Bruteforce 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            auto temp=intervals[i];
            if(ans.size()==0){
                ans.push_back(temp);
            }else{
                auto last_interval=ans.back();
                if(temp[0]<=last_interval[1]){
                    int new_start=min(temp[0],last_interval[0]);
                    int new_end=max(temp[1],last_interval[1]);
                    ans.pop_back();
                    ans.push_back({new_start,new_end});
                }else{
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
