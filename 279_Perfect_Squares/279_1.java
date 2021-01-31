class Solution {
    public int numSquares(int n) {
        int len = (int)Math.sqrt(n);
        List<Integer> squares = new ArrayList<>();
        for (int i = 1; i <= len; i++) {
            squares.add(i * i);
        }

        Set<Integer> queue = new HashSet<>();
        queue.add(n);
        int level = 0;
        while (!queue.isEmpty()) {
            level++;
            Set<Integer> nextQueue = new HashSet<>();
            for (Integer num : queue) {
                for (Integer squ : squares) {
                    if (num.equals(squ)) {
                        return level;
                    } else if (num < squ) {
                        break;
                    } else {
                        nextQueue.add(num - squ);
                    }
                }
            }
            queue = nextQueue;
        }
        return n;
    }
}
