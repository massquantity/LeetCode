#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int numDecodings(char *s){
  if (s[0] == '0') return 0;
  size_t n = strlen(s);
  if (n == 1) return 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == '0' && s[i-1] != '1' && s[i-1] != '2') {
      return 0;
    }
  }

  int dp[n];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  dp[1] = (s[1] == '0' || s[0] > '2' || (s[0] == '2' && s[1] > '6')) ? 1 : 2;
  for (int i = 2; i < n; i++) {
    if (s[i] == '0')
      dp[i] = dp[i-2];
    else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
      dp[i] = dp[i-1] + dp[i-2];
    else
      dp[i] = dp[i-1];
  }
  return dp[n-1];
}

int main(void) {
  printf("%d\n", numDecodings("101"));
}
