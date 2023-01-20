/*
Keep a count of all of the characters in the maganize and if any of the counts go below 0 when making the ransom note then false otherwise true
*/
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    if(magazine.length() < ransomNote.length()) return false;
    std::vector<int> counts(26, 0);
    for(int i = 0; i < magazine.length(); i++) counts[magazine[i] - 'a']++;
    for(int i = 0; i < ransomNote.length(); i++){
      if((--counts[ransomNote[i] - 'a']) < 0) return false;
    }
    return true;
  }
};
