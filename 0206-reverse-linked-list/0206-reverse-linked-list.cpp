/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseList(ListNode *head)
        {
            if (!head || head->next == NULL)
            {
                return head;
            }
            ListNode *prev = NULL;
            ListNode *curNode = head;
            ListNode *nextNode = head->next;
            while (curNode->next)
            {
                curNode->next = prev;
                prev = curNode;
                curNode = nextNode;
                nextNode = nextNode->next;
            }
            curNode->next = prev;
            return curNode;
        }
};