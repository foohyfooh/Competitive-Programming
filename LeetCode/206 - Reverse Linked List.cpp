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
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *prev = nullptr, *nextHead = nullptr;
    // While we have nodes following this one we need to redirect
    while(head->next != nullptr) {
      nextHead = head->next; // Keep track of the next node
      head->next = prev; // Redirect the current node to point to the previous
      prev = head;
      head = nextHead;
    }
    head->next = prev;
    return head;
  }
};
