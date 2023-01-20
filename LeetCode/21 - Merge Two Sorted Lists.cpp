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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // if(list1 == nullptr && list2 == nullptr) return nullptr;
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    ListNode *newHead = nullptr, *curr = nullptr;
    while(list1 != nullptr && list2 != nullptr) {
      if(list1->val <= list2->val) {
        if(newHead == nullptr) {
          newHead = curr = list1;
        } else {
          curr = curr->next = list1;
        }
        list1 = list1->next;
      } else {
        if(newHead == nullptr) {
          newHead = curr = list2;
        } else {
          curr = curr->next = list2;
        }
        list2 = list2->next;
      }
    }
    if(list1 == nullptr) curr->next = list2;
    else if(list1 != nullptr) curr->next = list1;
    return newHead;
  }
};
