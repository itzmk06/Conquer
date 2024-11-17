class Solution {
public:
    bool binarySearch(vector<int>& nums, int beg, int end, int target) {
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (target > nums[mid]) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        // handle beg
        int beg=0;
        int end=nums.size()-1; 
        while(beg<end&&nums[beg]==nums[end]){
            beg++;
        }
        // find minimum element in array

        int minIndex = -1;
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if(nums[mid]>nums[end]){
                beg=mid+1;
            }else{
                end=mid;
            }
        }
        minIndex=beg;
        bool result1 = binarySearch(nums, 0, minIndex-1, target);
        bool result2 =binarySearch(nums, minIndex , nums.size() - 1, target);
        return result1 || result2;
    }
};