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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* fast = head, *slow1 = head, *slow2 = head;
        int i = 1;
        while(i < k){
            fast = fast->next;
            ++i;
        }
        while(fast->next){
            fast = fast->next;
            slow1 = slow1->next;
        }
        i = 1;
        while(i < k){
            slow2 = slow2->next;
            ++i;
        }
        swap(slow1->val, slow2->val);
        return head;
    }
};