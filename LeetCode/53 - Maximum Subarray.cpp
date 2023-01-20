class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxSum = nums[0];
      int runningSum = 0;
      for (int num: nums) {
        if (runningSum < 0) runningSum = 0;
        runningSum += num;
        maxSum = max(maxSum, runningSum);
      }
      return maxSum;
    }
};
