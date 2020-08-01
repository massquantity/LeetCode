import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Map;
import java.util.HashMap;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Codec {
    public String serialize(TreeNode root) {
        if (root == null) return "null";
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        StringBuilder sb = new StringBuilder("[");
        while (!queue.isEmpty()) {
            TreeNode tmp = queue.poll();
            if (tmp == null) {
                sb.append("null" + ",");
            } else {
                sb.append(tmp.val + ",");
                queue.add(tmp.left);
                queue.add(tmp.right);
            }
        }
        sb.deleteCharAt(sb.length() - 1);
        sb.append("]");
        return sb.toString();
    }

    public TreeNode deserialize(String data) {
        if (data.equals("null")) return null;
        Queue<TreeNode> queue = new LinkedList<>();
        String[] ss = data.substring(1, data.length() - 1).split(",");
        TreeNode root = new TreeNode(Integer.parseInt(ss[0]));
        queue.add(root);
        int i = 1;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (!ss[i].equals("null")) {
                node.left = new TreeNode(Integer.parseInt(ss[i]));
                queue.add(node.left);
            }
            i++;
            if (!ss[i].equals("null")) {
                node.right = new TreeNode(Integer.parseInt(ss[i]));
                queue.add(node.right);
            }
            i++;
        }
        return root;
    }

    public static void traverse(TreeNode tree) {
        System.out.print(tree.val + " ");
        if (tree.left != null)  traverse(tree.left);
        if (tree.right != null) traverse(tree.right);
    }
}

public class leetcode {
    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        node1.left = node2;
        node1.right = node3;
        node3.left = node4;
        node4.right = node5;
        Codec s = new Codec();
        System.out.println(s.serialize(node1));

        TreeNode node = s.deserialize(s.serialize(node1));
        Codec.traverse(node);
    }
}


