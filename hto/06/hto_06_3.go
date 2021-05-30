import "fmt"

type ListNode struct {
	Val int 
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
    res := []int{}
    stack := []int{}
    for head != nil {
        stack = append(stack, head.Val)
        head = head.Next
    }
    for len(stack) != 0 {
        res = append(res, stack[len(stack)-1])
        stack = stack[:(len(stack)-1)]
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
