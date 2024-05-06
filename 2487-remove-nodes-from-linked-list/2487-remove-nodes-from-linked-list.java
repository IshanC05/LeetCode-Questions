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
    
    public ListNode removeNodes(ListNode head) {
        if(head.next == null)
            return head;
        
        head = reverseLL(head);
        ListNode res = head;
        ListNode tail = head;
        ListNode temp = head.next;
        
        while(temp != null){
            if(temp.val >= tail.val){
                tail.next = temp;
                tail = temp;
            }
            
            temp = temp.next;
        }
        
        tail.next = null;
        
        return reverseLL(res);
    }
}