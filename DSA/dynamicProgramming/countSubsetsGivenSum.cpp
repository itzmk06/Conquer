int subsetSum(vector<int>&arr,int k,int n){
	// intialization 
	int t[n+1][k+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<k+1;j++){
			if(i==0){
				t[i][j]=0;
			}
			if(j==0){
				t[i][j]=1;
			}
		}
	}
	// filling out values 
	for(int i=1;i<n+1;i++){
		for(int j=1;j<k+1;j++){
			if(arr[i-1]<=j){
				t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
			}else{
				t[i][j]=t[i-1][j];
			}
		}
	}
	// return the values 
	return t[n][k];

}
int findWays(vector<int>& arr, int k)
{
	// get the count 
	int n=arr.size();
	return subsetSum(arr,k,n);
}
