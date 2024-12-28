class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // to store cs and freq 
        unordered_map<int,int>mp;
        int result=0; 
        int cs=0;
        mp[0]=1; //because we saw 0 too 
        for(auto i:nums){
            // calculate cs 
            cs+=i;
            // if found cs - k, then we've got k 
            if(mp.find(cs-k)!=mp.end()){
                // increment result with freq of cs 
                result+=mp[cs-k];
            }
            // increment cs too 
            mp[cs]++;
        }
        return result;
    }
};