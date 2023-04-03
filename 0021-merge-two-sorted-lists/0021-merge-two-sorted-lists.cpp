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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }else if(l2 == NULL){
            return l1;
        }
        
        ListNode* head = new ListNode(-1);
        ListNode* tempHead = head;
        
        while(l1 and l2){
            if(l1->val > l2->val){
                tempHead->next = l2;
                l2 = l2->next;
            }else{
                tempHead->next = l1;
                l1 = l1->next;
            }
            tempHead = tempHead->next;
        }
        
        tempHead->next = (l1) ? l1 : l2;
        
        return head->next;
    }
};