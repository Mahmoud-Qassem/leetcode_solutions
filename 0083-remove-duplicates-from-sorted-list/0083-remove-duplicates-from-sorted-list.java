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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)return head;
        ListNode prev= head, myHead = head;
        head = head.next;

        while(head != null){
            ListNode crnt= head;
            if(crnt.val == prev.val){
                prev.next = crnt.next;
            }
            else 
                prev= crnt;
            head= head.next;
        }
        return myHead;
    }
}