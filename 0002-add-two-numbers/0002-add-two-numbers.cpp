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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        while(l1 and l2){
            int sum = carry + l1->val + l2->val;
            carry = 0;
            if(sum > 9){
                carry = carry + 1;
                sum = sum % 10;
            }
            ListNode* temp = new ListNode(sum);
            if(!ans){
                ans = temp;
                tail = ans;
            }else{
                tail->next = temp;
                tail = temp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            while(l1 and carry){
                l1->val = carry + l1->val;
                carry = 0;
                if(l1->val > 9){
                    carry = carry + 1;
                    l1->val = l1->val % 10;
                }
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            while(l1){
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
        }
        if(l2){
            while(l2 and carry){
                l2->val = carry + l2->val;
                carry = 0;
                if(l2->val > 9){
                    carry = carry + 1;
                    l2->val = l2->val % 10;
                }
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
            while(l2){
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if(carry){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        tail->next = NULL;
        return ans;
    }
};