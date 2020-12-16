bool checkInclusion(char * s1, char * s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    int map[26];
    int windowCnt[26];
    memset(map, 0, sizeof(map));
    memset(windowCnt, 0, sizeof(windowCnt));
    for (int i = 0; i < len1; i++) {
        map[s1[i] - 'a']++;
    }
    
    int left = 0, right = 0, distance = 0;
    for (int i = 0; i < 26; i++) {
        if (map[i] != 0) distance++;
    }
    
    while (right < len2) {
        char c = s2[right++] - 'a';
        if (map[c] > 0) {
            windowCnt[c]++;
            if (map[c] == windowCnt[c])
                distance--;
        }

        if (distance == 0) 
            return true;

        while (right - left >= len1) {
            
            char d = s2[left++] - 'a';
            if (map[d] > 0) {
                if (map[d] == windowCnt[d])
                    distance++;
                windowCnt[d]--;
            }
        }
    }
    return false;
}

int main(void) {
    printf("%s\n", checkInclusion("hello", "ooolleoooleh") ? "true" : "false");
}

