class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0;
        int end=nums.size()-1;
        while(beg<=end){
            int mid=(beg)+(end-beg)/2;
            if(nums[mid]==target){
                return mid;
            }else if(target>nums[mid]){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
};