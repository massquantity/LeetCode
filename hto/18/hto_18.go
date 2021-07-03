/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func deleteNode(head *ListNode, val int) *ListNode {
    if head == nil {
        return nil
    } else if head.Val == val {
        return head.Next
    }
    cur := head
    for cur.Next != nil && cur.Next.Val != val {
        cur = cur.Next
    }
    if cur.Next != nil {
        cur.Next = cur.Next.Next
    }
    return head
}
