/*
Need to be log n so have to do binary search but this requires sorted values and we don't have a set value to search for.
But it apparently still works if the sorted numbers are " rotated" i.e. [a[0], a[1], a[2], ..., a[n-1]] => [a[n-1], a[0], a[1], a[2], ..., a[n-2]]
Use bound [0, n) and binary search to keep checking if the right most value is greater than the mid until we reach the smallest number
*/
class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
      int mid = (left + right) / 2;
      if(nums[mid] < nums[right]) right = mid;
      else left = mid + 1;
    }
    return nums[left];
  }
};
