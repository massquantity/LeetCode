type CQueue struct {
    stack1 []int
    stack2 []int
}


func Constructor() CQueue {
    return CQueue{[]int{}, []int{}}
}


func (this *CQueue) AppendTail(value int)  {
    this.stack1 = append(this.stack1, value)
}


func (this *CQueue) DeleteHead() int {
    if len(this.stack1) == 0 && len(this.stack2) == 0 {
        return -1
    } else if len(this.stack2) == 0 {
        for len(this.stack1) != 0 {
            top := this.stack1[len(this.stack1) - 1]
            this.stack2 = append(this.stack2, top)
            this.stack1 = this.stack1[:len(this.stack1) - 1]
        }
    }
    head := this.stack2[len(this.stack2) - 1]
    this.stack2 = this.stack2[:len(this.stack2) - 1]
    return head
}
