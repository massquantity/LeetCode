class Solution {
    public int[] singleNumbers(int[] nums) {
        int ret = 0;
        for (int num : nums) 
            ret ^= num;
        
        int mask = 1;
        while ((ret & mask) == 0)
            mask <<= 1;
        
        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & mask) == 0) 
                a ^= num;
            else
                b ^= num;
        }
        return new int[]{a, b};
    }
}