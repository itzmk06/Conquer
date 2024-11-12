// * using bit manipulation o(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result=0;
        for(int num:nums){
            result=result^num;
        }
        return result;
    }
};

// * optimal using binary search 0(log n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int beg=0;
        int end=nums.size()-1;
        while(beg<end){
            int mid=beg+(end-beg)/2;
            // to make pairing easy 
            if(mid%2!=0){
                mid--;
            }
            // if mid element = mid next element -> not disrupted search right 
            if(nums[mid]==nums[mid+1]){
                beg=mid+2;
            }else{
                end=mid;
            }
        }
        return nums[beg];
    }
};