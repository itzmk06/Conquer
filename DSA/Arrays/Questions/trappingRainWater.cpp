class Solution {
public:
    vector<int> generateLeftMax(vector<int>&height,int n){
        // create a vector of size n
        vector<int>left(n);
        // intialize first place
        left[0]=height[0];
        // iterate with other places -> place max of previous or hieght 
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        return left;
    }
    vector<int> generateRightMax(vector<int>&height,int n){
        // create an right 
        vector<int>right(n);
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        return right;
    }
    int trap(vector<int>& height) {
        int size=height.size();
        // generate left max 
        vector<int>left=generateLeftMax(height,size);
        // generate right max
        vector<int>right=generateRightMax(height,size);
        // calculate the sum of area of water 
        int sum=0;
        for(int i=0;i<size;i++){
            sum+=(min(left[i],right[i])-height[i]);
        }
        return sum;
    }
};
