func deleteNode(head *ListNode, val int) *ListNode {
    if head == nil {
        return nil
    } else if head.Val == val {
        return head.Next
    }
    head.Next = deleteNode(head.Next, val)
    return head
}
