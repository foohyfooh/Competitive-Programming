#include <string.h>

#define MAX_SIZE 10000
char string[MAX_SIZE + 1], pattern[MAX_SIZE + 1];

int n = strlen(&string[1]), m = strlen(&pattern[1]);
int prefix[m + 1];

prefix[1] = 0;
for(int q = 2, k = 0; q <= m; q++){
  while(k > 0 && pattern[k + 1] != pattern[q])  k = prefix[k];
  if(pattern[k + 1] == pattern[q]) k++;
  prefix[q] = k;
}

for(int i = 1, q = 0; i <= n; i++){
  while(q > 0 && pattern[q + 1] != string[i]) q = prefix[q];
  if(pattern[q + 1] == string[i]) q++;
  if(q == m){
    //printf("Pattern occurs with shift %d\n", i - m);
    q = prefix[q];
  }
}
