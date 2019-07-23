int binarySearchForInsertion(int arr[], int start, int end, int value){
	int mid;
	while(start < end){
		mid = start + (end - start)/2;
		if(arr[mid] == value) return mid;
		else if(arr[mid] > value) start = mid + 1;
		else end = mid - 1;
	}
	if(start > end) return end + 1;
	if(arr[start] > value) return start;
	return start + 1;
}
