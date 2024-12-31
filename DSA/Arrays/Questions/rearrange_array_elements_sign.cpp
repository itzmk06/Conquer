// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// * Bruteforce 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        // traverse 
        for(int i:nums){
            if(i<0){
                pos.push_back(i);
            }else{
                neg.push_back(i);
            }
        }
        // add to result 
        nums.clear();
        int j=0;
        int k=0;
        for(int i=0;i<2*pos.size();i++){
            if(i%2!=0){
                nums.push_back(pos[j]);
                j++;
            }else{
                nums.push_back(neg[k]);
                k++;
            }
        }
        return nums;
    }
};


// * optimal 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     vector<int>result(nums.size());
        // traverse array
        int p=0;
        int n=1; 
        for(int i:nums){
            if(i>=0&&p<nums.size()){
                // put in even index
                result[p]=i;
                p+=2;
            }else{
                // put in odd index
                if(n<nums.size()){
                    result[n]=i;
                n+=2;
                }
            }
        } 
        return result;
    }
};
