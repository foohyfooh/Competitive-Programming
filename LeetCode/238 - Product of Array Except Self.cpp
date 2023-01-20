class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int numSize = nums.size();
    vector<int> products(numSize, 1);
    for(int i = 0, left = 1, right = 1, end = numSize - 1; i < numSize; i++) {
      products[i] *= left;
      left *= nums[i];
      int rightPos = end - i;
      products[rightPos] *= right;
      right *= nums[rightPos];
    }
    return products;
  }
};
