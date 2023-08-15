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
    ListNode* partition(ListNode* head, int x) {
        
        if(!head || !head->next)    return head;
        
        ListNode* lessHead = nullptr, *lessTail, *moreHead = nullptr, * moreTail = nullptr;
        
        ListNode* temp = head;
        
        while(temp){
            
            if(temp->val < x){
                
                if(!lessHead){
                    
                    lessHead = temp;
                    
                    lessTail = temp;
                    
                }else{
                    
                    lessTail->next = temp;
                    
                    lessTail = temp;
                    
                }
                
            }
            
            else{
                
                if(!moreHead){
                    
                    moreHead = temp;
                    
                    moreTail = temp;
                    
                }else{
                    
                    moreTail->next = temp;
                    
                    moreTail = temp;
                    
                }
                
                
            }
            
            temp = temp->next;           
            
        }
        
        if(moreTail)    moreTail->next = nullptr;
        
        if(!lessHead)   return moreHead;
        
        lessTail->next = moreHead;
        
        return lessHead;
        
    }
};