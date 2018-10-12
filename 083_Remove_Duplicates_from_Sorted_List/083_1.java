public class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode res = head;
        while (res != null && res.next != null)
        {
            if (res.val == res.next.val)
                res.next = res.next.next;
            else
                res = res.next;
        }   
        return head;
    }