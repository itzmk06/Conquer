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
// * using hashset 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        // create set, to remove duplicates 
        unordered_set<int>numSet(nums.begin(),nums.end());
        // no longest find so far 
        int longest=0;
        // iterate over nums, get smallest element 
        // which means there's no previous element to that 
        for(auto num:numSet){
            if(numSet.find(num-1)==numSet.end()){
                // we didn't find any previous element 
                // check whether for current element there's consecutive element 
                int currentNum=num;
                int count=1;
                while(numSet.find(currentNum+1)!=numSet.end()){
                    // found a consecutive element, increment count 
                    count++;
                    // check for next consecutive number 
                    currentNum++; 
                }
                // update longest 
                longest=max(count,longest);
            }
        }
        return longest;
    }
};
