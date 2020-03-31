#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a, b, c) ((a) < ((b) < (c) ? (b) : (c)) ? (a) : ((b) < (c) ? (b) : (c)));

// this method is slow...
int dpFunc(char *word1, char *word2, int i, int j) {
    if (i == -1) return j + 1;
    if (j == -1) return i + 1;
    if (word1[i] == word2[j])
        return dpFunc(word1, word2, i - 1, j - 1);
    else
        return 1 + min(dpFunc(word1, word2, i - 1, j - 1), 
                       dpFunc(word1, word2, i, j - 1), 
                       dpFunc(word1, word2, i - 1, j));
}


int minDistance(char * word1, char * word2){
    return dpFunc(word1, word2, strlen(word1) - 1, strlen(word2) - 1);
}
