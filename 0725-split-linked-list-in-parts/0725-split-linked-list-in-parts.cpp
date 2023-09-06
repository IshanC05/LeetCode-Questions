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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int sz = 0;
        
        ListNode* temp = head, *prev = nullptr;
        
        while(temp){
            ++sz;
            temp = temp->next;
        }
        
        temp = head;
        
        vector<ListNode*>ans(k);
        
        if(sz <= k){
            
            int i = 0;
            
            while(k--){
                
                ans[i] = temp;
                
                if(temp)    temp = temp->next;
                
                if(ans[i])  ans[i]->next = nullptr;
                
                i++;
                
            }
            
        }
        
        else{
            
            int extraNodes = sz % k;
            
            int sizeOfGroup = sz / k, j = 0;
            
            bool adjust = false;
            
            while(temp){
                
                ans[j++] = temp;
                
                for(int i = 0; i < sizeOfGroup; i++){
                    
                    prev = temp;
                    
                    temp = temp->next;                   
                    
                }
                
                if(extraNodes){
                    
                    prev = temp;
                    
                    temp = temp->next;
                    
                    --extraNodes;
                    
                }
                
                prev->next = nullptr;
                
            }
            
        }
        
        return ans;
        
    }
};