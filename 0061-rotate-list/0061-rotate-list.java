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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null){
            return head;
        }

        int length = 1;
        ListNode tail = head;
        while(tail.next != null){
            tail = tail.next;
            length++;
        }

        k = k % length;
        if(k == 0){
            return head;
        }

        ListNode tail2 = head;

        int i = 0;
        while(i < length - k -1){
            i++;
            tail2 = tail2.next;
        }

        ListNode head2 = tail2.next;
        tail.next = head;
        tail2.next = null;

        return head2;
    }
}