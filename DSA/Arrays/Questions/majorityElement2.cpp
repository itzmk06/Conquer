// * Bruteforce

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>frequency;
        // traverse whole array 
        for(int i=0;i<nums.size();i++){
            // store freq 
            frequency[nums[i]]++;
        }
        // traverse map and store numbers on condition into vector 
        for(auto i=frequency.begin();i!=frequency.end();i++){
            if(i->second>(nums.size()/3)){
                ans.push_back(i->first);
            }
        }
        return ans;


    }
};

// * optimal 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int maj1=-1;
        int maj2=-1;
        for(int num:nums){
            if(maj1==num){
                count1++;
            }else if(maj2==num){
                count2++;
            }else if(count1==0){
                maj1=num;
                count1=1;
            }else if(count2==0){
                maj2=num;
                count2=1;
            }else {
                count1--;
                count2--;
            }
        }


        int freq1=0;
        int freq2=0;
        for(int num:nums){
            if(num==maj1){
                freq1++;
            }
            if(num==maj2){
                freq2++;
            }
        }
        vector<int>ans;

        if(freq1>(nums.size()/3)){
            ans.push_back(maj1);
        }
         if(freq2>(nums.size()/3)&&maj1!=maj2){
            ans.push_back(maj2);
        }
        return ans;

    }
};
