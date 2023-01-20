/*
Basically brute force extending the current built up string until its length is 2*n
If the number of parenthesis match then it is added to set
*/
class Solution {
public:
  bool doParenthesisMatch(string& s) {
    int count = 0;
    for(char c: s) {
      if(c == '(') count++;
      else count--; // c == ')'
      if(count < 0) return false;
    }
    return count == 0;
  }

  void makePattern(vector<string>& patterns, int strLimit, string built = ""){
    if(built.length() > strLimit) return;
    if(built.length() == strLimit && doParenthesisMatch(built)) {
      patterns.push_back(built);
      return;
    };
    if(built.length() == strLimit - 1){ // Last character can only )
      makePattern(patterns, strLimit, built + ")");
    } else {
      makePattern(patterns, strLimit, built + "(");
      makePattern(patterns, strLimit, built + ")");
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> patterns;
    makePattern(patterns, 2 * n, "(");
    return patterns;
  }
};
