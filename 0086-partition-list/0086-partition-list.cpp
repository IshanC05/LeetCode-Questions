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
        
        if(!head || !head->next)
            return head;
        
        ListNode* temp = head;
        vector<int>arr;
        
        while(temp){
            if(temp->val < x){
                arr.push_back(temp->val);
            }
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp){
            if(temp->val >= x){
                arr.push_back(temp->val);
            }
            temp = temp->next;
        }
        
        temp = head;
        
        int i = 0, n = arr.size();
        
        while(i < n){
            temp->val = arr[i++];
            temp = temp->next;
        }
        
        return head;
    }
};