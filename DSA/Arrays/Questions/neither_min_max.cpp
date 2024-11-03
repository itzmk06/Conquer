// * Brute force 0(n)

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxElement=INT_MIN;
        int minElement=INT_MAX;
        int selectedElement=-1;
        for(int num:nums){
            if(num>maxElement){
                maxElement=num;
            }
            if(num<minElement){
                minElement=num;
            }
        }
        for(int num:nums){
            if(num!=maxElement&&num!=minElement){
                selectedElement=num;
                return selectedElement;
            }
        }
        return selectedElement;
    }
};

// * optmal one 
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        // if length is <3 return -1 
        if(nums.size()<3) return -1 ;
        // take three elements at random 
        int a=nums[0],b=nums[1],c=nums[2];
        if((a>b&&a<c)||(a>c&&a<b)) return a;
        else if((b>a&&b<c)||(b>c&&b<a)) return b;
        else return c; 
        return -1;
    }
};