// https://leetcode.com/problems/best-sightseeing-pair/?envType=daily-question&envId=2024-12-27
// * brutre force
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=INT_MIN;
        for(int i=0;i<values.size()-1;i++){
            for(int j=i+1;j<values.size();j++){
                int current_score=((values[i]+i)+(values[j]-j));
                maxi=max(current_score,maxi);
            }
        }
        return maxi;
    }
};

// * optimal 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=INT_MIN;
        int maxLeft=values[0]+0;
        for(int i=1;i<values.size();i++){
            maxi=max(maxi,maxLeft+(values[i]-i));
            maxLeft=max(maxLeft,values[i]+i);
        }
        return maxi;
    }
};
