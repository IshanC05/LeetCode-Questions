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
        if(!head || !head->next){
            return NULL;
        }
        unordered_set<ListNode*>m;
        ListNode* temp = head;
        while(temp){
            if(m.count(temp)){
                return temp;
            }else{
                m.insert(temp);
            }
            temp = temp->next;
        }
        return NULL;
    }
};