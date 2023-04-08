/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        bool isPalindrome(ListNode *head)
        {
            ListNode *tempHead = head;
            stack<int> s;
            while (tempHead != NULL)
            {
                s.push(tempHead->val);
                tempHead = tempHead->next;
            }

            while (head != NULL)
            {
                if (head->val != s.top())
                {
                    return false;
                }
                s.pop();
                head = head->next;
            }
            return true;
        }
};