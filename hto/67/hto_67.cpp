class Solution {
public:
    int strToInt(string str) {
        if (str == "") return 0;
        size_t len = str.size();
        int i = 0;
        long res = 0;
        while (str[i] == ' ') i++;
        if (i == len) return 0;
        bool sign = str[i] == '-' ? false : true;
        if (str[i] == '+' || str[i] == '-') i++;
        while (i < len && isdigit(str[i])) {
            res = res * 10 + str[i] - '0';
            if (sign && res > INT_MAX) return INT_MAX;
            else if (!sign && -res < INT_MIN) return INT_MIN;
            i++;
        }
        return sign ? res : -res;
    }
};