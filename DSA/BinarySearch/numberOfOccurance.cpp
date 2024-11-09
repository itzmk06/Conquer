int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int beg=0;
	int end=arr.size()-1;
	// get first occurance 
	int firstResult=-1;
	int lastResult=-1;
	while(beg<=end){
		int mid=beg+(end-beg)/2;
		if(arr[mid]==x){
			firstResult=mid;
			end=mid-1;
		}else if(x>arr[mid]){
			beg=mid+1;
		}else{
			end=mid-1;
		}
	}
	// reset beg and end to find last occurance 
	beg=0;
	end=arr.size()-1;
	while(beg<=end){
		int mid=beg+(end-beg)/2;
		if(arr[mid]==x){
			lastResult=mid;
			beg=mid+1;
		}else if(x>arr[mid]){
			beg=mid+1;
		}else{
			end=mid-1;
		}
	}
	if(lastResult==-1||firstResult==-1){
		return 0;
	}
	return lastResult-firstResult+1;
}
