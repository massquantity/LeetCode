class Solution {
    public int minArray(int[] numbers) {
        if (numbers.length == 1) return numbers[0];
        int len = numbers.length;
        int lo = 0, hi = len - 1;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (numbers[mid] < numbers[hi])
                hi = mid;
            else if (numbers[mid] > numbers[hi])
                lo = mid + 1;
            else
                hi--;
        }
        return numbers[lo];
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[] array = {2, 2, 2, 0, 1};
        Solution s = new Solution();
        System.out.println(s.minArray(array));
    }
}