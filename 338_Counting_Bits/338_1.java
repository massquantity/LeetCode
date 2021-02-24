class Solution {
    public int[] countBits(int num) {
        List<Integer> tmp = new ArrayList<>();
        tmp.add(0);
        for (int i = 1; i <= num; i++) {
            int m = i;
            int n = 1;
            while (m != 1) {
                n += m % 2;
                m >>>= 1;
            }
            tmp.add(n);
        }
        int[] res = new int[tmp.size()];
        for (int i = 0; i < res.length; i++) {
            res[i] = tmp.get(i).intValue();
        }
        return res;
    }
}
