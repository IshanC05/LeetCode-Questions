/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseLL(ListNode head){
        if(head == null || head.next == null)   return head;
        
        ListNode newHead = reverseLL(head.next);
        ListNode tail = head.next;
        
        head.next = null;
        tail.next = head;
        
        return newHead;
    }
    public boolean isPalindrome(ListNode head) {
        if(head.next == null)   return true;
        
        int n = 0;
        ListNode prev = head;
        
        while(prev != null){
            prev = prev.next;
            ++n;
        }
        
        prev = null;
        ListNode slow = head;
        ListNode fast = head;
        ListNode head2 = null;
        
        while(fast != null && fast.next != null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        prev.next = null;
        
        head2 = slow;
        
        if(n % 2 != 0)  head2 = slow.next;
        
        head = reverseLL(head);
        
        while(head != null && head2 != null){
            if(head.val != head2.val)   return false;
            head = head.next;
            head2 = head2.next;
        }
        
        return true;
    }
}