class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* l = head;
        ListNode* r = head;
        while(r){
            if(r->val != 0){
                if(l != r){
                    l->val = l->val + r->val;
                }else{
                    l->val = r->val;
                }
            }else{
                l->next = r->next;
                l = l->next;
            }
            r = r->next;
        }
        return head;
    }
};