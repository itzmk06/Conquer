class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            int minIndex=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[minIndex]){
                    minIndex=j;
                }
            }
            if(minIndex!=i){
                swap(nums[i],nums[minIndex]);
            }
        }
        return nums;
    }
};