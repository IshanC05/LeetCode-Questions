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
    ListNode* reverseLL(ListNode* head){
        
        if(!head || !head->next)
            return head;
        
        ListNode* prev = nullptr, *curr = head, *nextNode = head->next;
        
        while(nextNode){
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        
        curr->next = prev;
        
        return curr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        l1 = reverseLL(l1), l2 = reverseLL(l2);
        
        int carry = 0;
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            sum = sum + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            if(!tail){
                ans = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        
        return reverseLL(ans);
    }
};