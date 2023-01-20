class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    maxSum = nums[0]
    runningSum = 0
    for num in nums:
      if runningSum < 0: runningSum = 0
      runningSum += num
      maxSum = max(maxSum, runningSum)
    return maxSum
