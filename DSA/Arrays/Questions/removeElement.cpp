// * my approach 

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=1;
        int n=nums.size();
        if(n==0){
            return 0;
        }

        while(j<n){
            if(nums[j]!=val){
                if(nums[i]!=val){
                    i++;
                    nums[i]=nums[j];
                }else{
                    nums[i]=nums[j];
                }
            }
            j++;
        }
        if(nums[i]==val){
            return 0;
        }else{
            return i+1;
        }

    }
};

//* chat bhai's approach
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;

    }
};
