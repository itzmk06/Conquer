// * 0(n)-> time and 0(n)-> space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int maxIndex=INT_MIN;
        int maxElement=INT_MIN;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second>maxIndex){
                maxIndex=i->second;
                maxElement=i->first;
            }
        }
        return maxElement;
    }
};

// * optimal 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int majority=NULL;
        // traverse whole array 
        for(int num:nums){
            // if count = 0, assume that element as majority 
            if(count==0){
                majority=num;
                // increase the count 
                count=1;
            }else if(num==majority){
                // increase count
                count++;
            }else{
                // this is new element 
                // decrement count 
                count--;
            }
        }
        return majority;
    }
};
