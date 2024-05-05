/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode curr) {
        ListNode prev = null;
        ListNode nextNode = curr.next;
        
        while(nextNode != null){
            if(prev != null)    
                prev.val = curr.val;
            
            prev = curr;
            curr = nextNode;
            nextNode = nextNode.next;
        }
        
        if(prev != null)    
                prev.val = curr.val;
        
        prev.next = null;
    }
}