import "fmt"

type ListNode struct {
	Val int 
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
    if head == nil {
        return []int{}
    }
    res := reversePrint(head.Next)
    res = append(res, head.Val)
    return res
}

func main() {
	node1 := &ListNode{1, nil}
	node2 := &ListNode{2, nil}
	node3 := &ListNode{3, nil}
	node1.Next = node2
	node2.Next = node3
	fmt.Println(reversePrint(node1))
}
