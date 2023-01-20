/*
Just go through the list and check if the node has been visited already
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      unordered_map<ListNode*, bool> visited;
      for(; head != nullptr; head = head->next){
        if(visited.find(head) != visited.end()) return true;
        visited[head] = true;
      }
      return false;
    }
};
