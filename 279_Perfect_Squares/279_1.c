#define min(a, b) (a) < (b) ? (a) : (b)
/*
int numSquares(int n){
    int nums = sqrt((double)n) + 1;
    int square_nums[nums];
    for (int i = 0; i < nums; i++) {
        square_nums[i] = pow(i, 2);
    }
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < nums; j++) {
            if (square_nums[j] > i)
                break;
            dp[i] = min(dp[i], dp[i - square_nums[j]] + 1);
        }
    }
    return dp[n];
} */

bool is_in(int n, int *square_nums, int nums) {
    for (int i = 0; i < nums; i++) {
        if (n == square_nums[i]) {
            return true;
        }
    }
    return false;
}

bool is_divided_by(int n, int count, int *square_nums, int nums) {
    if (count == 1) {
        return is_in(n, square_nums, nums);
    }
    for (int i = 0; i < nums; i++) {
        if (is_divided_by(n - square_nums[i], count - 1, square_nums, nums)) {
            return true;
        }
    }
    return false;
}

int numSquares(int n) {
    int nums = sqrt((double)n) + 1;
    int square_nums[nums];
    for (int i = 0; i < nums; i++) {
        square_nums[i] = pow(i, 2);
    }
    for (int count = 1; count < n + 1; count++) {
        if (is_divided_by(n, count, square_nums, nums))
            return count;
    }
    return n;
}
