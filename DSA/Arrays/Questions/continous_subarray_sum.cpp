// https://leetcode.com/problems/continuous-subarray-sum/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // create an unordered map to store mod and it's first occrance of index 
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        // iterate over the vector 
        for(int i=0;i<nums.size();i++){
            // get the cummulative sum 
            sum+=nums[i];
            // get the mod 
            int mod=sum%k;
            // if the mod is already present check for length else store the mod 
            if(mp.find(mod)!=mp.end()){
                if(i-mp[mod]>=2){
                    // means found subarray that's good with lenght 2 or >
                    return true;
                }
            }else{
                // mod not found store the mod 
                mp[mod]=i;
            }
        }
        return false;
    }
};
