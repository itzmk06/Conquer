// * brute force 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        // traverse whole array 
        for(int i=0;i<nums.size();i++){
            int product=1;
            for(int j=i;j<nums.size();j++){
                product*=nums[j];
                maxi=max(product,maxi);
            }
        }
        return maxi;
    }
};


// * optimal approach 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=nums[0];
        int currMax=nums[0];
        int currMin=nums[0];
        for(int i=1;i<nums.size();i++){
            // get element
            int num=nums[i];
            // if negative reverse the elments 
            if(num<0){
                swap(currMax,currMin);
            }
            // get max product till now 
            currMax=max(num,currMax*num);
            currMin=min(num,currMin*num);
            // update product max 
            maxProduct=max(currMax,maxProduct);
        }
        return maxProduct;
    }
};
