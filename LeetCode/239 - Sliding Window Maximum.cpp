class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(k == 1) return nums;
    vector<int> maxes;
    maxes.reserve(nums.size() - k + 1);
    std::deque<int> Q; // Double sided queue
    for(int i = 0; i < nums.size(); i++) {
      // Since queue should be in decreasing order, the values at the end can't be the max for the current window being considered
      // so we can remove them until we reach a number that is >= to the current number
      while(!Q.empty() && Q.back() < nums[i]) Q.pop_back();
      Q.push_back(nums[i]);
      // If the max value right now is the number before the current start of the sliding window then it needs to be removed
      // Otherwise it can stay since it is somewhere in the window
      if(i >= k && nums[i - k] == Q.front()) Q.pop_front();
      if(i >= k - 1) maxes.push_back(Q.front());
    }
    return maxes;
  }
};
