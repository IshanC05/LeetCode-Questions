class Solution
{
    public:
        ListNode* deleteDuplicates(ListNode *head)
        {
            if (!head)
            {
                return head;
            }
            unordered_map<int, int> freq;
            ListNode *tempHead = head;
            while (tempHead)
            {
                ++freq[tempHead->val];
                tempHead = tempHead->next;
            }
            ListNode *l = head, *r = head;
            while (r != NULL and freq[r->val] > 1)
            {
                r = r->next;
            }
            if (r == NULL)
            {
                return r;
            }
            head = r;
            l = r;
            while (r)
            {
                if (freq[r->val] == 1 and l->val != r->val)
                {
                    l->next = r;
                    l = r;
                }
                r = r->next;
            }
            l->next = NULL;
            return head;
        }
};