//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int multiply(int mid,int n,int m){
	    long long result=1;
	    for(int i=0;i<n;i++){
	        result*=mid;
	        if(result>m){
	            return 2;
	        }
	    }
	        if(result==m){
	            return 1;
	        }
	        return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if(m<=1){
	        return m;
	    }
	    int beg=0;
	    int end=m;
	    while(beg<=end){
	        int mid=beg+(end-beg)/2;
	        int result=multiply(mid,n,m);
	        if(result==1){
	           return mid;
	        }else if(result==0){
	            beg=mid+1;
	        }else{
	            end=mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends