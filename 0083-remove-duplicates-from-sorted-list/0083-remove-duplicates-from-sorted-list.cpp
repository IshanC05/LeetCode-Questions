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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* l=head;
        ListNode* r=head;
        
        while(r != NULL){
            if(r->val != l->val){
                l->next = r;
                l=r;
            }
            r = r->next;
        }
        l->next=NULL;
        return head;
    }
};