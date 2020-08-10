class Solution {
    public int[] levelOrder(TreeNode root) {
        if (root == null) return new int[0];
        List<List<Integer>> list = new ArrayList<>();
        bfs(root, 0, list);

        int count = 0;
        for (List<Integer> l : list) {
            count += l.size();
        }
        int[] res = new int[count];
        int i = 0;
        for (List<Integer> l : list) {
            for (Integer j : l) {
                res[i] = j;
                i++;
            }
        }
        return res;
    }

    private void bfs(TreeNode node, int level, List<List<Integer>> list) {
        if (level >= list.size()) 
            list.add(new ArrayList<>());
        list.get(level).add(node.val);
        if (node.left != null)  bfs(node.left,  level + 1, list);
        if (node.right != null) bfs(node.right, level + 1, list);
    }
}