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
        if(!l1 and !l2){
            return l1;
        }
        if(!l1){
            return l2;
        }else if(!l2){
            return l1;
        }
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        while(l1 and l2){
            ListNode* temp = NULL;
            if(l1->val > l2->val){
                temp = l2;
                l2 = l2->next;
            }else{
                temp = l1;
                l1 = l1->next;
            }
            if(ans == NULL){
                ans = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        while(l1){
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        while(l2){
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
        return ans;
    }
};