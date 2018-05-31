class ListNode 
    {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

public class test
{
    public static ListNode removeNthFromEnd(ListNode head, int n)
    {
        ListNode ans = new ListNode(0);
        ans.next = head;

        ListNode val1 = ans, val2 =ans;
        int i = 0;
        while (i < n){
            val1 =  val1.next;
            i++;
        }

        while (val1.next != null){
            val1 = val1.next;
            val2 = val2.next;
        }
        val2.next = val2.next.next;
        return ans.next;   
    }

    public static void main(String[] args)
    {
        ListNode a = new ListNode(0);
        ListNode b = new ListNode(1);
        a.next = b;
        ListNode c = new ListNode(3);
        b.next = c;
        ListNode d = new ListNode(4);
        c.next = d;
        ListNode e = new ListNode(5);
        d.next = e;

        a = removeNthFromEnd(a, 2);
        while (a != null)
        {
            System.out.println(a.val);
            a = a.next;    
        }
    }
}