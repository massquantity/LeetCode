import "fmt"

type ListNode struct {
	Val int 
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	var prev *ListNode
	for head != nil {
		tmp := head.Next
		head.Next = prev
		prev = head
		head = tmp
	}
	res := []int{}
	for prev != nil {
		res = append(res, prev.Val)
		prev = prev.Next
	}
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
