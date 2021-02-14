class Solution {
    public int findDuplicate(int[] nums) {
        int left = 1, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right) >>> 1;
            int cnt = 0;
            for (int n : nums) {
                if (n <= mid)
                    cnt++;
            }

            if (cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
