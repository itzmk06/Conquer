pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	// finding floor first 
	int beg=0;
	int end=a.size()-1;
	int floorElement=-1;
	while(beg<=end){
		int mid=beg+(end-beg)/2;
		if(a[mid]<=x){
			floorElement=a[mid];
			beg=mid+1;
		}else{
			end=mid-1;
		}
	}
	// now search the ceil 
	int ceilElement=-1;
	beg=0;
	end=a.size()-1;
	while(beg<=end){
		int mid=beg+(end-beg)/2;
		if(a[mid]>=x){
			ceilElement=a[mid];
			end=mid-1;
		}else{
			beg=mid+1;
		}
	}
	pair<int,int>ans;
	ans.first=floorElement;
	ans.second=ceilElement;
	return ans;
}