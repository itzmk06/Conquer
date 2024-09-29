//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int k) {
        vector<long long>ans;
        deque<int>q;
        
        // let's traverse fist k elements 
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                q.push_back(i);
            }
        }
        
        // let's traverse remaining elements 
        for(int i=k;i<N;i++){
            // print ans for previous window 
            if(q.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(arr[q.front()]);
            }
            
            // remove out of index window element 
            while(!q.empty()&&(i-q.front()>=k)){
                q.pop_front();
            }
            
            // insert negative element if present 
            if(arr[i]<0){
                q.push_back(i);
            }
            
        }
        if(q.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(arr[q.front()]);
        }
        return ans;
 }