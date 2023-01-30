/*
Create a set to keep track of the items we have seen before
If we have seen it them return true
Else remove the last value from the set if set at size k then insert the current number
*/
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(k == 0) return false;
    unordered_set<int> window;
    for(int i = 0; i < nums.size(); i++) {
      if(window.find(nums[i]) != window.end()) return true;
      if(window.size() == k) window.erase(nums[i - k]);
      window.insert(nums[i]);
    }
    return false;
  }
};
