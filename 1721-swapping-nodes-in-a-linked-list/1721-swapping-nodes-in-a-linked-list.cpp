class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1=head, *n2=head, *temp = head;
        while(temp){
            if(k == 0){
                n2 = n2->next;
            }if(k != 0){
                n1 = temp;
                --k;
            }
            temp = temp->next;
        }
        swap(n1->val, n2->val);
        return head;
    }
};