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
        if(!head || !head->next){
            return head;
        }
        
        ListNode* smallHead = reverseLL(head->next);
        ListNode* tail = head->next;
        tail->next = head;
        head->next = nullptr;
        
        return smallHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right){
            return head;
        }

        ListNode* slow = head, *fast = head, *prevSlow = nullptr, *prevFast = nullptr;
        
        int i = 0;
        while(i < right and fast){
            prevFast = fast;
            fast = fast->next;
            ++i;
        }
        prevFast->next = nullptr;
        
        i = 1;
        while(i < left and slow){
            prevSlow = slow;
            slow = slow->next;
            ++i;
        }
        
        ListNode* reverseHead = reverseLL(slow);
        
        if(prevSlow == nullptr){
            head = reverseHead;
        }else{
            prevSlow->next = reverseHead;
        }
        
        slow->next = fast;
        
        return head;
    }
};