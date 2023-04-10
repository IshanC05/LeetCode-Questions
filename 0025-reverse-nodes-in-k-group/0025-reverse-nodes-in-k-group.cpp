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
    ListNode* reverseLL(ListNode* head){
        if(!head){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nextNode = head->next;
        while(cur->next){
            cur->next = prev;
            prev = cur;
            cur = nextNode;
            nextNode = nextNode->next;
        }
        cur->next = prev;
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1){
            return head;
        }
        ListNode* length = head;
        int len = 0;
        while(length){
            ++len;
            length = length->next;
        }
        if(len < k){
            return head;
        }else if(len == k){
            return reverseLL(head);
        }
        ListNode* tempHead = head;
        int i=1, tempK = k;
        while(i != tempK){
            ++i;
            tempHead = tempHead->next;
        }
        ListNode* head2 = tempHead->next;
        tempHead->next = NULL;
        ListNode* firstReversed = reverseLL(head);
        ListNode* restLL = reverseKGroup(head2, k);
        tempHead = firstReversed;
        while(tempHead->next){
            tempHead = tempHead->next;
        }
        tempHead->next = restLL;
        return firstReversed;
    }
};