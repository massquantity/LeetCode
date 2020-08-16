class Solution {
    public double[] twoSum(int n) {
        double[] res = new double[5*n+1];
        int[] dp = new int[6*n+1];
        for (int i = 1; i <= 6; i++) {
            dp[i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 6*i; j >= i; j--) {
                dp[j] = 0;
                for (int k = 1; k <= 6; k++) {
                    if (j - k >= i - 1)
                        dp[j] += dp[j-k];
                }
            }
        }
        double denominator = Math.pow(6, n);
        for (int i = n; i <= 6*n; i++) {
            res[i-n] = dp[i] / denominator;
        }
        return res;
    }
}

