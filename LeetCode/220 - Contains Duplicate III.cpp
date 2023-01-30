/*
Create a sorted set to keep track of the items we have seen before
Get the first number that is greater than or equal to the current number - the max difference
If it the absolute difference is less than max difference return true
Else remove last value if set size is at index difference and insert new number
*/
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    set<int> window;
    for(int i = 0; i < nums.size(); i++) {
      set<int>::iterator it = window.lower_bound(nums[i] - valueDiff);
      if(it != window.end() && abs(*it - nums[i]) <= valueDiff) return true;
      if(window.size() == indexDiff) {
        window.erase(nums[i - indexDiff]);
      }
      window.insert(nums[i]);
    }
    return false;
  }
};
