// * Bruteforce

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>frequency;
        // traverse whole array 
        for(int i=0;i<nums.size();i++){
            // store freq 
            frequency[nums[i]]++;
        }
        // traverse map and store numbers on condition into vector 
        for(auto i=frequency.begin();i!=frequency.end();i++){
            if(i->second>(nums.size()/3)){
                ans.push_back(i->first);
            }
        }
        return ans;


    }
};
