class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0]);
        List<int[]> res = new LinkedList<>();
        for (int[] i : people) {
            res.add(i[1], i);
        }
        return res.toArray(new int[res.size()][2]);
    }
}
