class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // sort array 
        sort(nums.begin(),nums.end());
        // get size of array 
        int n=nums.size();
        // either it can be a combination of last three max elemnets 
        int maxProduct1=nums[n-1]*nums[n-2]*nums[n-3];
        // either it can be two negative and 1 largest 
        int maxProduct2=nums[0]*nums[1]*nums[n-1];
        // return max 
        return max(maxProduct1,maxProduct2);

    }
};