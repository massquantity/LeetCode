package main

type TreeNode struct {
    Val int
    Left *TreeNode
     Right *TreeNode
}

 func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil
    }
    indexMap := map[int]int{}
    for i, t := range inorder {
        indexMap[t] = i
    }
    return buildBranch(indexMap, preorder, inorder, 0, 0, len(preorder) - 1)
}

func buildBranch(indexMap map[int]int, preorder []int, inorder []int, first int, left int, right int) *TreeNode{
    if left > right {
        return nil
    }
    root := &TreeNode{preorder[first], nil, nil}
    mid := indexMap[preorder[first]]
    root.Left = buildBranch(indexMap, preorder, inorder, first+1, left, mid-1)
    root.Right = buildBranch(indexMap, preorder, inorder, first+mid-left+1, mid+1, right)
    return root
}
