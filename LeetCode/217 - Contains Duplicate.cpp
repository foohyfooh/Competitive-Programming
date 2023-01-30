/*
Sort the numbers and check if any number matches the previous one
*/
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 0, end = nums.size() - 1; i < end; i++) {
      if(nums[i] == nums[i + 1]) return true;
    }
    return false;
  }
};
