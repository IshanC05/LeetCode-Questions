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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        int len = 0;
        ListNode* length = head;
        while(length){
            ++len;
            length = length->next;
        }
        if(len == n){
            head = head->next;
            return head;
        }
        ListNode* temp = head;
        while(n--){
            temp = temp->next;
        }
        ListNode* prev=NULL;
        ListNode* cur = head;
        while(temp){
            prev = cur;
            cur = cur->next;
            temp = temp->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};