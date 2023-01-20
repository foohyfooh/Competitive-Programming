/*
Keep track of the front and back of the string
While the pointers haven't crossed
  Go until the first alphanumeric character for each pointer and compare
If all the comparisons match then return true
*/
class Solution {
public:
  bool isPalindrome(string s) {
    int front = 0, back = s.length() - 1;
    while(front < back) {
      while(front < back && !isalnum(s[front])) ++front;
      while(front < back && !isalnum(s[back])) --back;
      if(tolower(s[front]) != tolower(s[back])) return false;
      ++front; --back;
    }
    return true;
  }
};
