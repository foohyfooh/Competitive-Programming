/*
Do binary search with special cases
If left portion is properly sorted
  Check if the number is in that portion and decide how to move left and right
Else the right portion should properly sorted
  Check if the number is in that portion then decide how to move left and right
*/
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, mid;
    while(left <= right) {
      mid = (left + right) / 2;
      if(nums[mid] == target) return mid;
      else if(nums[left] <= nums[mid]) { // This portion [left .. mid] should be sorted properly
        if (nums[left] <= target && target <= nums[mid]) right = mid - 1;
        else left = mid + 1;
      } else { // nums[mid] <= nums[right] // This portion [mid .. right] should be sorted properly
        if(nums[mid] <= target && target <= nums[right]) left = mid + 1;
        else right = mid - 1;
      }
    }
    return -1;
  }
};
