package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func mirrorTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	tmp := root.Left
	root.Left = root.Right
	root.Right = tmp
	if root.Left != nil {
		mirrorTree(root.Left)
	} 
	if root.Right != nil {
		mirrorTree(root.Right)
	}
	return root
}

func main() {
	root := new(TreeNode)
	root.Val = 1
	node1 := new(TreeNode)
	node1.Val = 2
	node2 := new(TreeNode)
	node2.Val = 7
	root.Left = node1
	root.Right = node2
	root = mirrorTree(root)
	fmt.Println(root.Val, root.Left.Val, root.Right.Val)
}
