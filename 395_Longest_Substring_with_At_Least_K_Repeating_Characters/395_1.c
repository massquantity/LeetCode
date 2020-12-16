#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int recursive(const char *s, int k, int left, int right) {
    if (right - left + 1 < k) return 0;
    int map[26];
    memset(map, 0, sizeof map);
    for (int i = left; i <= right; i++) {
        map[s[i] - 'a']++;
    }

    while (right - left + 1 >= k && map[s[left]  - 'a'] < k) left++;
    while (right - left + 1 >= k && map[s[right] - 'a'] < k) right--;
    if (right - left + 1 < k) return 0;
    for (int i = left; i <= right; i++) {
        if (map[s[i] - 'a'] < k) {
            return max(recursive(s, k, left, i - 1),
                       recursive(s, k, i + 1, right));
        }
    }
    return right - left + 1;
}

int longestSubstring(char *s, int k){
    int len = strlen(s);
    if (len == 0 || k > len) return 0;
    if (k < 2) return len;
    return recursive(s, k, 0, len - 1);
}

int main(void) {
    printf("%d\n", longestSubstring("ababacb", 3));
}
