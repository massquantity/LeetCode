import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Stack;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public boolean isValidBST(TreeNode root) {
    	Stack<TreeNode> stack = new Stack<>();
    	long lastVal = Long.MIN_VALUE;
    	while (!stack.isEmpty() || root != null) {
    		while (root != null) {
    			stack.push(root);
    			root = root.left;
    		}
    		root = stack.pop();
    		if (root.val <= lastVal) return false;
    		lastVal = root.val;
    		root = root.right;
    	}
    	return true;
    }
}