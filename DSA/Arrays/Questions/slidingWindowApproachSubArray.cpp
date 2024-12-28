#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>result;
    vector<int>nums={10,20,30};
    int i=0;
    int j=0;
    int window_size=2;
    int window_sum=0;
    while(j<nums.size()){
        window_sum+=nums[j];
        if(j-i+1==window_size){
            result.push_back(window_sum);
            window_sum-=nums[i];
            i++;
        }
        j++;
    }
    cout<<"Printing sub array sum:\n";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" "<<endl;
    }
    return 0;
}