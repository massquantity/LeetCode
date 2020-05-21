import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

class Solution {
    List<List<Integer>> res = new LinkedList<>();

    public List<List<Integer>> permute(int[] nums) {
        LinkedList<Integer> track = new LinkedList<>();
        backtrack(nums, track);
        return res;
    }

    private void backtrack(int[] nums, LinkedList<Integer> track) {
        if (track.size() == nums.length) {
            res.add(new LinkedList<>(track));
            return;
        }

        for (int i = 0; i < nums.length; ++i) {
            if (track.contains(nums[i])) continue;
            track.add(nums[i]);
            backtrack(nums, track);
            track.removeLast();
        }
    }
}

public class leetcode {
    public static void main(String[] args) {
        int[] a = {1, 2, 3};
        Solution s = new Solution();
        List<List<Integer>> res = s.permute(a);
        for (List<Integer> i : res) {
            for (Integer j : i)
                System.out.print(j + " ");
            System.out.println();
        }
        // System.out.println(res);
    }
}

