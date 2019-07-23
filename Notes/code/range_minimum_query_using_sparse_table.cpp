int sparseTable[0 .. log2(N)][0 .. N];

for(int i = 1; i <= log2(N); i++){
  int length = 1 << (i - 1);
  for(int j = 1; j + length <= sparseTable[i - 1][0]; j++){
    sparseTable[i][j] = min(sparseTable[i - 1][j], sparseTable[i - 1][j + length]);
    sparseTable[i][0] = j;
  }
}
