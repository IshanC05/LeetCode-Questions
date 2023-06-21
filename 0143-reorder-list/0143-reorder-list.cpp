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
     void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        stack<ListNode*> st;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            st.push(curr);
            curr = curr->next;
        }

        curr = head;
        ListNode* nextNode = curr->next;

        while (!st.empty()) {
            ListNode* top = st.top();
            st.pop();
            curr->next = top;
            top->next = nextNode;
            curr = nextNode;

            if (nextNode == nullptr) {
                break;
            }

            nextNode = nextNode->next;
        }
     }
};