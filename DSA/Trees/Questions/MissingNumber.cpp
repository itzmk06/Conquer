// * My approach => 0(nlogn)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(count==nums[i]){
                count++;
            }else{
            return count;
            }
        }
        return count;
    }
};

//* optimal approach => 0(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xors=0;
        int xorNums=0;
        for(int i=0;i<=nums.size();i++){
            xors^=i;
        }
        for(int n:nums){
            xorNums^=n;
        }
        return xorNums^xors;
    }
};