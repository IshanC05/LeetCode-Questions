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
        ListNode* removeNodes(ListNode *head)
        {
            if (!head || !head->next)
            {
                return head;
            }
            head = reverseList(head);
            ListNode *i = head, *j = head;
            while (j)
            {
                if (i->val > j->val)
                {
                    i->next = j->next;
                    // i = j->next;
                }
                else
                {
                    i = j;
                }
                j = j->next;
            }
            head = reverseList(head);
            return head;
        }
};