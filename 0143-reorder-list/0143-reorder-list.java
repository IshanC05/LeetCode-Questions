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
    public ListNode reverse(ListNode head){
        if(head == null || head.next == null)   return head;
        
        ListNode newHead = reverse(head.next);
        ListNode tail = head.next;
        
        head.next = null;
        tail.next = head;
        
        return newHead;
    }
    public void reorderList(ListNode head) {
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

        if(n % 2 == 0){
            head2 = slow;
            prev.next = null;
        }else{
            head2 = slow.next;
            slow.next = null;
        }

        head2 = reverse(head2);

        ListNode res = head, tail = head;
        head = head.next;

        boolean turn = false;

        while(head != null || head2 != null){ // Corrected condition
            if(turn){
                tail.next = head;
                tail = head;
                head = head.next;
            }else{
                tail.next = head2;
                tail = head2;
                head2 = head2.next;
            }

            turn = !turn;
        }

        head = res;

        return;
    }

}