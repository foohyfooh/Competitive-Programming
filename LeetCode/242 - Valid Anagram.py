'''
Sort both of the strings and compare their equality
'''
class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    return sorted(s) == sorted(t)
