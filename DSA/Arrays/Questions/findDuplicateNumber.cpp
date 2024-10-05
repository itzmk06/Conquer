class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // make slow and fast to point to 0 
        int s=0;
        int f=0;
        // make slow and fast to move to thier positions since range is [1,n]
        int slow=nums[s];
        int fast=nums[nums[f]];
        // until a cycle is formed move them 
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        // if i come out of loop it means slow = fast => cycle is present 
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        // now came out means slow=fast => both are pointing to same element 
        return slow;

    }
};