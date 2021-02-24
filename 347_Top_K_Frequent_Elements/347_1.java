class Solution {
    int n = 0;
    int arr[];
    Map<Integer, Integer> counts = new HashMap<>();
    public int[] topKFrequent(int[] nums, int k) {
        int size = nums.length;
        for (int num : nums) {
            if (!counts.containsKey(num))
                counts.put(num, 1);
            else
                counts.put(num, counts.get(num) + 1);
        }

        arr = new int[size + 1];
        for (Integer num : counts.keySet()) {
            arr[++n] = num.intValue();
            swim(n);
        }

        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = popMax();
        }
        return res;
    }

    private void swim(int k) {
        while (k > 1 && counts.get(arr[k/2]) < counts.get(arr[k])) {
            swap(arr, k/2, k);
            k /= 2;
        }
    }

    private void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && counts.get(arr[j]) < counts.get(arr[j+1])) j++;
            if (counts.get(arr[k]) >= counts.get(arr[j])) break;
            swap(arr, k, j);
            k = j;
        }
    }

    private int popMax() {
        int max = arr[1];
        swap(arr, 1, n--);
        sink(1);
        return max;
    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
