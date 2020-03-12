import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Stack;


class Solution {
    public int numTrees(int n) {
    	int[] res = new int[n + 1];
    	res[0] = 1;
    	res[1] = 1;
    	for (int i = 2; i <= n; i++) {
    		for (int j = 1; j <= i; j++) {
    			res[i] += res[j - 1] * res[i - j];
    		}
    	}
    	return res[n];
    }
}


public class leetcode {
	public static void main(String[] args) {
		Solution s =  new Solution();
		System.out.println(s.numTrees(3));
	}
}

