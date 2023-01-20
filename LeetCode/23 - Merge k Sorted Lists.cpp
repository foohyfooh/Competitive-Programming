/*
Add all the values to an array and sort it then create a new sorted list
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return {};
    if(lists.size() == 1) return lists[0];
    vector<int> values;
    for(ListNode* list: lists) {
      while(list != nullptr) {
        values.push_back(list->val);
        list = list->next;
      }
    }
    sort(values.begin(), values.end());
    ListNode *head = nullptr, *curr = nullptr;
    for(int value: values){
      if(head == nullptr) {
        head = curr = new ListNode(value);
      } else {
        curr->next = new ListNode(value);
        curr = curr->next;
      }
    }
    return head;
  }
};
