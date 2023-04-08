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
        if(head->next->next == NULL){
            return (head->val + head->next->val);
        }
        ListNode* length = head;
        int i=0;
        while(length){
            ++i;
            length = length->next;
        }
        ListNode* left = head;
        stack<int>st;
        int n = i;
        i=0;
        while(i < n/2){
            st.push(left->val);
            ++i;
            left = left->next;
        }
        int ans = 0;
        while(left and !st.empty()){
            ans = max(ans, left->val + st.top());
            left = left->next;
            st.pop();
        }
        return ans;
    }
};