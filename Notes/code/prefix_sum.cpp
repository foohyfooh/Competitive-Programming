int A[N + 1], sums[N + 1];

void calcPrefixSums(){
  sums[1] = A[1];
  for(int i = 2; i <= N; i++)
    sums[i] = sums[i - 1] + A[i];
}

int query(int start, int end){
  return sums[end] - sums[start - 1];
}
