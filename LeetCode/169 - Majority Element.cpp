/*
Basically Moore's voting algorithm
Since they told us to assume a majority exists then not doing the final check part
*/
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 0, candidate;
    for(int num: nums) {
      if(count == 0) {
        candidate = num;
        count = 1;
      } else if(num == candidate) count++;
      else count--;
    }
    // count = 0;
    // for(int num: nums) {
    //   if(num == candidate) count++;
    // }
    // if(count > nums.size() / 2) return candidate;
    return candidate;
  }
};
