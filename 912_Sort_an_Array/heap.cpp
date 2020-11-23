#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    Heap() = default;
    bool isEmpty();
    void insert(int i);
    int delMax();

private:
    int N = 0;
    vector<int> arr{0};
    void swim(int k);
    void sink(int k);
};

bool Heap::isEmpty() {
    return N == 0;
}

void Heap::insert(int i) {
    arr.push_back(i);
    N++;
    swim(N);
}

int Heap::delMax() {
    int max = arr[1];
    swap(arr[1], arr[N--]);
    sink(1);
    return max;
}

void Heap::swim(int k) {
    while (k > 1 && arr[k/2] < arr[k]) {
        swap(arr[k/2], arr[k]);
        k /= 2;
    }
}

void Heap::sink(int k) {
    while (2*k <= N) {
        int j = 2*k;
        if (j < N && arr[j] < arr[j+1]) j++;
        if (arr[j] <= arr[k]) break;
        swap(arr[j], arr[k]);
        k = j;
    }
}

class Heap2 {
public:
    Heap2() = default;
    void insert(int i);
    int delMax();
    bool isEmpty();

private:
    vector<int> arr;
    void swim(int k);
    void sink(int k);
};

void Heap2::insert(int i) {
    arr.push_back(i);
    swim(arr.size() - 1);
}

int Heap2::delMax() {
    int max = arr[0];
    swap(arr[0], arr[arr.size()-1]);
    arr.pop_back();
    sink(0);
    return max;
}

bool Heap2::isEmpty() {
    return arr.empty();
}

void Heap2::swim(int k) {
    while (k > 0) {
        int j = (k - 1) / 2;
        if (arr[j] < arr[k]) {
            swap(arr[j], arr[k]);
            k = j;
        } else {
            break;
        }
    }
}

void Heap2::sink(int k) {
    int N = arr.size();
    while (2*k + 1 < N) {
        int j = 2*k + 1;
        if (j < N - 1 && arr[j] < arr[j+1]) j++;
        if (arr[j] <= arr[k]) break;
        swap(arr[j], arr[k]);
        k = j;
    }
}

int main() {
    Heap2 heap;
    heap.insert(1);
    heap.insert(3);
    heap.insert(-22);
    heap.insert(8);
    heap.insert(-1);
    while (!heap.isEmpty()) {
        cout << heap.delMax() << " ";
    }
}
