// * Bruteforce
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count=0;
        unordered_map<int,int>mp;
        // traverse array 
        for(int i=0;i<nums.size();i++){
            // find whether already inserted or not 
            if(mp.find(nums[i])==mp.end()){
                // insert element 
                mp.insert({nums[i],i});
            }else{
                // already present 
                while(true){
                    nums[i]++;
                    count++;
                    if(mp.find(nums[i])==mp.end()){
                        mp.insert({nums[i],i});
                        break;
                    }
                }
            }
        }
        return count;

    }
};
