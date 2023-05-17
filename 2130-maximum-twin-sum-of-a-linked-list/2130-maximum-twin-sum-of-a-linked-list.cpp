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
    int pairSum(ListNode* head) {
        if(!head){
            return 0;
        }
        ListNode* temp = head, *length = head;
        int res = 0, i = 0, n = 0;
        while(length){
            ++n;
            length = length->next;
        }
        stack<int>st;
        while(i < n / 2){
            st.push(temp->val);
            ++i;
            temp = temp->next;
        }
        while(temp and !st.empty()){
            res = max(res, st.top() + temp->val);
            st.pop();
            temp = temp -> next;
        }
        return res;
    }
};