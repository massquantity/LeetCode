class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0) return new int[][]{newInterval};
        int i = 0;
        LinkedList<int[]> res = new LinkedList<>();
        while (intervals[i][1] < newInterval[0]) {
            res.add(intervals[i]);
            i++;
            if (i == intervals.length) break;
        }
        res.add(newInterval);
        for (; i < intervals.length; i++) {
            if (intervals[i][0] > res.getLast()[1]) {
                res.add(intervals[i]);
            } else {
                res.getLast()[0] = Math.min(res.getLast()[0], intervals[i][0]);
                res.getLast()[1] = Math.max(res.getLast()[1], intervals[i][1]);
            }
        }
        return res.toArray(new int[0][]);
    }
}