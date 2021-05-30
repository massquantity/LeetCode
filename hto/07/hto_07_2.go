func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 || len(preorder) != len(inorder) {
        return nil
    }

    rootVal := preorder[0]
    rootIndex := 0
    for i, n := range inorder {
        if n == rootVal {
            rootIndex = i
        }
    }
    leftPre, rightPre := preorder[1:rootIndex+1], preorder[rootIndex+1:]
    leftIn, rightIn := inorder[:rootIndex], inorder[rootIndex+1:]
    left := buildTree(leftPre, leftIn)
    right := buildTree(rightPre, rightIn)
    return &TreeNode{Val: rootVal, Left: left, Right: right}
}
