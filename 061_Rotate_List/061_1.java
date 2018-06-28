public class ListNode 
{
    int val;
    ListNode next;
        ListNode(int x) { val = x; }
}

class Solution
{
    public ListNode rotateRight(ListNode head, int k)
    {
        if (head == null || k == 0) return head;
        ListNode current = head;
        int count = 1;
        while (current.next != null)
        {
            current = current.next;
            count++;
        }

        current.next = head;
        for (int i = 0; i < (count - k % count); i++)
            current = current.next;
        head = current.next;
        current.next = null;
        return head;
    }
}