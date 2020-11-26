#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

char * minWindow(char * s, char * t){
    int map[128];
    memset(map, 0, sizeof(map));
    int len_s = strlen(s), len_t = strlen(t);
    int i = 0, needCnt = len_t, left = 0, right = INT_MAX;
    for (int j = 0; j < len_t; j++) {
        map[t[j]] += 1;
    }
    for (int j = 0; j < len_s; j++) {
        char c_right = s[j];
        if (map[c_right] > 0) needCnt--;
        map[c_right]--;
        if (needCnt == 0) {
            while (true) {
                char c_left = s[i];
                if (map[c_left] == 0) break;
                else  {
                    map[c_left]++;
                    i++;
                }
            }
            if (j - i < right - left) {
                left = i;
                right = j;
            }
            map[s[i]]++;
            needCnt++;
            i++;
        }
    }

    if (right > len_s) return "";
    else {
        char *res = (char *)malloc(sizeof(char) * (right - left + 2));
        memcpy(res, &s[left], right - left + 1);
        res[right - left + 1] = '\0';
        return res;
    }
}


int main(void) {
    char *s = s = "ADOBECODEBANC", *t = "ABC";
    printf("%s\n", minWindow(s, t));
}

