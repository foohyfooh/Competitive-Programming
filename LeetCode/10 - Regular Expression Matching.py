'''
Check that both are empty i.e. pattern matched all the text
If the pattern is [a-z.]* then check that either (no characters match this part of the pattern) or (the first character matches and check rest of text with the pattern)
Else check that the current character matches and the rest of pattern matches
'''
class Solution:
  def doesFirstMatch(self, text: str, pattern: str) -> bool:
    return bool(text) and (pattern[0] == text[0] or pattern[0] == '.')

  def collapseMultimatch(self, pattern: str) -> str:
    while pattern[0:2] == pattern[2:4]:
      pattern = pattern[2:]
    return pattern

  def isMatch(self, text: str, pattern: str) -> bool:
    if not bool(pattern):
      return not bool(text)
    if len(pattern[0:2]) == 2 and pattern[1] == '*':
      pattern = self.collapseMultimatch(pattern)
      return self.isMatch(text, pattern[2:]) or (self.doesFirstMatch(text, pattern) and self.isMatch(text[1:], pattern))
    else:
      return self.doesFirstMatch(text, pattern) and self.isMatch(text[1:], pattern[1:])
