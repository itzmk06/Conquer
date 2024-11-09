class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        // find the first occurance 
        int beg=0;
        int end=nums.size()-1;
        int firstResult=-1;
        int lastResult=-1;
        // get first occurance 
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(nums[mid]==target){
                firstResult=mid;
                end=mid-1;
            }else if(target>nums[mid]){
                beg=mid+1;
            }else{ 
                end=mid-1;
            }
        }
        // get last occurance 
        beg=0;
        end=nums.size()-1;
        while(beg<=end){
            int mid=(beg)+(end-beg)/2;
            if(nums[mid]==target){
                lastResult=mid;
                beg=mid+1;
            }else if(target>nums[mid]){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        // update the first and last occurance 
        ans[0]=firstResult;
        ans[1]=lastResult;
        return ans;
    }
};