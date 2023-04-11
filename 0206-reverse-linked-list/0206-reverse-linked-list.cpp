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
        if(!head || !head->next){
            return head;
        }
        ListNode* cur = head;
        ListNode* smallAns = reverseList(head->next);
        ListNode* temp = smallAns;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = cur;
        cur->next = NULL;
        return smallAns;
    }
};