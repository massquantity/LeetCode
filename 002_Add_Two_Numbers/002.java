public class Solution
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode dummy = new ListNode(0);
        int sum = 0, carry = 0;
        ListNode curr = dummy;
        while (l1 != null || l2 != null || carry != 0)
        { 
            int num1 = l1 == null? 0 : l1.val;
            int num2 = l2 == null? 0 : l2.val;
            sum = num1 + num2 + carry;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            carry = sum / 10;
            l1 = l1 == null? null : l1.next;
            l2 = l2 == null? null : l2.next;
        }
        if (carry != 0)
            curr.next = new ListNode(carry);
        return dummy.next;
    }
}