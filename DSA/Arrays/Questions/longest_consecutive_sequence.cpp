// * bruteforce (0(nlogn))
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if no elements no consecutive
        if(nums.empty()) return 0;
        // sort
        sort(nums.begin(),nums.end());
        // because, instailly if only 1 element is there it's considered as consecutive 
        int count=1;
        int longest=1;
        for(int i=1;i<nums.size();i++){
            // skip duplicates 
            if(nums[i]==nums[i-1]) continue;
            // in consecutive increase count
            if(nums[i]==nums[i-1]+1){
                // current one is +1 then previous one 
                count++;
            }else{
                // not consecutive 
                // update longest so far and set back count to 1 
                longest=max(count,longest);
                count=1;
            }
        }
        // we're checking here too becuase it's completly consecutive, we're not updating longest so 
        return max(longest,count);

    }
};
