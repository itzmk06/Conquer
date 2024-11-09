class Solution {
public:
    int findMin(vector<int>& nums) {
        // get beg and end 
        int beg=0;
        int n=nums.size();
        int end=n-1;
        // if it's already sorted 
        if(nums[beg]<=nums[end]){
            return nums[beg];
        }
        // nahi tho 
        while(beg<=end){
            // calculate mid element 
            int mid=beg+(end-beg)/2;
            // that min element will be lesser than prev and less then next element 
            if(nums[mid]<nums[(mid-1+n)%n]&&nums[mid]<nums[(mid+1+n)%n]){
                return nums[mid];
            }else if(nums[mid]>nums[end]){
                // this means this is the unsorted part (right side to mid ele)
                beg=mid+1;
            }else{
                // this means left side to mid element is unsorted 
                end=mid-1;
            }
        }
        return -1;
    }
};