// https://leetcode.com/problems/target-sum/?envType=daily-question&envId=2024-12-26
// * Brute force 
class Solution {
public:
    int solve(vector<int>&nums,int target,long long current_sum,int i){
        if(i==nums.size()){
            if(target==current_sum){
                return 1;
            }
            return 0;
        }

        // add 
        int plus=solve(nums,target,current_sum+nums[i],i+1);
        // minus
        int minus=solve(nums,target,current_sum-nums[i],i+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long long current_sum=0;
        return solve(nums,target,current_sum,0);
    }
};

// * using hashmaps instead of vectors for memoization 
class Solution {
public:
    unordered_map<string,int>mp;
    int solve(vector<int>&nums,int target,long long current_sum,int i){
        if(i==nums.size()){
            if(target==current_sum){
                return 1;
            }
            return 0;
        }
        string key=to_string(i)+"_"+to_string(current_sum);
        if(mp.count(key)){
            return mp[key];
        }
        // add 
        int plus=solve(nums,target,current_sum+nums[i],i+1);
        // minus
        int minus=solve(nums,target,current_sum-nums[i],i+1);
        return mp[key]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long long current_sum=0;
        return solve(nums,target,current_sum,0);
    }
};

// * using memoization of vectors 
class Solution {
public:
    int MAX_SUM;
    int solve(vector<int>&nums,int target,long long current_sum,int i,vector<vector<int>>&t){
        if(i==nums.size()){
            if(target==current_sum){
                return 1;
            }
            return 0;
        }
        // if already present return it 
        if(t[i][current_sum+MAX_SUM]!=-1){
            return t[i][current_sum+MAX_SUM];
        }
        // add 
        int plus=solve(nums,target,current_sum+nums[i],i+1,t);
        // minus
        int minus=solve(nums,target,current_sum-nums[i],i+1,t);
        return t[i][current_sum+MAX_SUM]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long long current_sum=0;
        int n=nums.size();
        // get total sum 
        MAX_SUM=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>t(n,vector<int>(2*MAX_SUM+1,-1));
        return solve(nums,target,current_sum,0,t);
    }
};
