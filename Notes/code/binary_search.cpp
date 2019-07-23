int binarySearch(int arr[], int start, int end, int value){
	int mid;
	while(start <= end){
		mid = start + (end - start)/2;
		if(arr[mid] == value) return mid;
		else if(arr[mid] > value) start = mid + 1;
		else end = mid - 1;
	}
	return -1;
}
