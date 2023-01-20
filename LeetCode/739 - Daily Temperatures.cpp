/*
Keep a stack of indexes of the temperatures which we encounter
For each temp
  Keep checking the current temp against the last one stored in the stack
  If the current temp is greater than the last one then this index minus the stored index is the number of days
  After that store the current temp's index so that we can check if a higher temp comes after it
*/
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<int> stack;
    for(int i = 0; i < temperatures.size(); ++i) {
      while(!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
        int topIndex = stack.top(); stack.pop();
        ans[topIndex] = i - topIndex;
      }
      stack.push(i);
    }
    return ans;
  }
};
