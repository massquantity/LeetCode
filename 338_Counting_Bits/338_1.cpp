class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; i++) {
            res[i] = pop_count(i);
        }
        return res;
    }

    int pop_count(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++; 
        }
        return count;
    }
};
