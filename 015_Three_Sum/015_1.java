import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
    	List<List<Integer>> res = new ArrayList<>();
    	Arrays.sort(nums);
    	int length = nums.length;
    	for (int i = 0; i < length - 2; ++i) {
    		if (i == 0 || (i > 0 && nums[i - 1] < nums[i])) {
    			int j = i + 1;
    			int k = length - 1;
    			while (j < k) {
	    			int threeSum = nums[i] + nums[j] + nums[k];
	    			if (threeSum == 0) {
	    				res.add(Arrays.asList(nums[i], nums[j], nums[k]));
	    				while (j < k && nums[j] == nums[j + 1]) j++;
	    				while (j < k && nums[k] == nums[k - 1]) k--;
	    				j++;
	    				k--;
	    			} else if (threeSum < 0) {
	    				j++;
	    			} else {
	    				k--;
	    			}
    			}
    		}
    	}
    	return res;
    }
}


public class leetcode {
	public static void main(String[] args) {
		int[] nums = {-1,0,1,2,-1,-4};
		Solution s = new Solution();
		List<List<Integer>> res = s.threeSum(nums);
		for (List<Integer> a : res) {
			System.out.print('[');
			for (Integer b : a)
				System.out.print(b + " ");
			System.out.print(']');
			System.out.println();
		}
	}
}