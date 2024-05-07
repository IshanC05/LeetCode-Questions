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
        if(head == null || head.next == null)
            return head;
        
        ListNode newHead = reverseLL(head.next);
        ListNode tail = head.next;
        
        head.next = null;
        tail.next = head;
        
        return newHead;
    }
    
    public ListNode doubleIt(ListNode head) {
        head = reverseLL(head);
        
        ListNode tempHead = head;
        ListNode prev = null;
        
        int carry = 0;
        
        while(tempHead != null){
            tempHead.val = (tempHead.val * 2) + carry;
            
            carry = tempHead.val / 10;
            tempHead.val = tempHead.val % 10;
            
            prev = tempHead;
            
            tempHead = tempHead.next;
        }
        
        if(carry != 0)
            prev.next = new ListNode(carry);
        
        return reverseLL(head);
    }
}