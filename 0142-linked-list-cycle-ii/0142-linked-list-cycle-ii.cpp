/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next)    return nullptr;
        
        ListNode* slow = head, *fast = head, *loopNode = head;
        bool loop = false;
        
        while(fast && fast->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow){
                loop = true;
                break;
            }
        }
        
        if(slow != fast)    return nullptr;
        

        while(slow != loopNode){
            slow = slow->next;
            loopNode = loopNode->next;
        }
            
        return loopNode;
    }
};