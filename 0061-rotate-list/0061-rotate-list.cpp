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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next == NULL){
            return head;
        }
        int len = 0;
        ListNode* length = head;
        while(length){
            ++len;
            length = length->next;
        }
        int rotations = k % len;
        if(rotations == 0){
            return head;
        }
        int last = len - rotations;
        ListNode* prev = NULL, *cur = head;
        int i = 0;
        while(i < last){
            ++i;
            prev = cur;
            cur = cur->next;
        }
        ListNode* newHead = cur;
        prev->next = NULL;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = head;
        return newHead;
    }
};