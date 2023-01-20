# Need to keep track of the current running min and max since a negation could make that the next min or max
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
      max_product = temp_min = temp_max = nums[0]
      for num in nums[1:]:
        num_by_min = num * temp_min
        num_by_max = num * temp_max
        temp_min = min(num, min(num_by_min, num_by_max))
        temp_max = max(num, max(num_by_min, num_by_max))
        max_product = max(max_product, temp_max)
      return max_product
