class Solution {
public:
    int binarySearch(vector<int>&nums,int target,int beg,int end){
        while(beg<=end){
            int mid=beg+(end-beg)/2;
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
    int search(vector<int>& nums, int target) {
        int beg=0;
        int size=nums.size();
        int end=size-1;
        // if already sorted apply normal bs
        if(nums[beg]<=nums[end]){
            return binarySearch(nums,target,beg,end);
        }        
        // if rotated array first find out first element -> min element 
        beg=0;
        end=size-1;
        int midIndex=-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(nums[mid]<nums[(mid+size-1)%size]&&nums[mid]<nums[(mid+1)%size]){
                midIndex=mid;
                break;
            }else if(nums[mid]>nums[end]){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        // now you've your first element 
        // check whether you're target element is greater or lesser 
        if(target>=nums[0]&&target<=nums[midIndex-1]){
            return binarySearch(nums,target,0,midIndex-1);
        }else{
            return binarySearch(nums,target,midIndex,size-1);
        }
        return -1;
    }
};