class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL and head->val == val){
            head = head->next;
        }
        if(head == nullptr){
            return head;
        }
        ListNode* l = nullptr;
        ListNode* r = head;
        
        while(r){
            if(r->val == val){
                l->next = r->next;
            }else{
                l = r;
            }
            r = r->next;
        }
        return head;
    }
};