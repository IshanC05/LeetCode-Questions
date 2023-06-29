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
    int pairSum(ListNode* head) {
        
        ListNode* slow = head, *fast = head, *prev = nullptr;
        
        int ans = 0;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
        
        slow = reverseList(slow);
        prev = head;
        
        while(prev){
            ans = max(ans, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        
        return ans;
    }
};