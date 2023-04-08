/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* mergeNodes(ListNode *head)
        {
            if (!head)
            {
                return head;
            }
            ListNode *newHead = NULL;
            ListNode *tail = NULL;
            int sum = 0;
            while (head != NULL and head->val == 0)
            {
                head = head->next;
            }
            while (head)
            {
                if (head->val != 0)
                {
                    sum = sum + head->val;
                }
                else
                {
                    ListNode *temp = new ListNode(sum);
                    if (newHead == NULL)
                    {
                        newHead = temp;
                        tail = newHead;
                    }
                    else
                    {
                        tail->next = temp;
                        tail = temp;
                    }
                    sum = 0;
                }
                head = head->next;
            }
            return newHead;
        }
};