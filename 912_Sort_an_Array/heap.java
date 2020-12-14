class Heap {
    private int[] arr;
    private int n = 0;

    public Heap(int size) {
        arr = new int[size + 1];
    }

    Boolean isEmpty() {
        return n == 0;
    }

    void insert(int v) {
        arr[++n] = v;
        swim(n);
    }

    int popMax() {
        int max = arr[1];
        swap(arr, 1, n--);
        sink(1);
        return max;
    }

    void swim(int k) {
        while (k > 1 && arr[k/2] < arr[k]) {
            swap(arr, k/2, k);
            k /= 2;
        }
    }

    void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && arr[j] < arr[j+1]) j++;
            if (arr[k] >= arr[j]) break;
            swap(arr, k, j);
            k = j;
        }
    }

    void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

public class heap {
    public static void main(String[] args) {
        Heap h = new Heap(10);
        h.insert(1);
        h.insert(4);
        h.insert(-2);
        h.insert(-12);
        h.insert(111);
        while (!h.isEmpty()) {
            System.out.print(h.popMax() + " ");
        }
        System.out.println();
    }
}