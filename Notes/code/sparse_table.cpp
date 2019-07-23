#include <cmath>
#define log_2(x) ((int) log2(x))

int A[N]; A[0] = N;
int sparseTable[log_2(N)][N];

template<typename F>
void buildSparseTable(F func){
  sparseTable[0] = A;
  for(int i = 1; i <= log_2(N); i++){
    int length = 1 << (i - 1);
    for(int j = 1; j + length <= sparseTable[i - 1][0]; j++){
      sparseTable[i][j] = func(sparseTable[i - 1][j], sparseTable[i - 1][j + length]);
      sparseTable[i][0] = j;
    }
  }
}

template<typename F>
int query(int start, int end, F func){
  if(start == end) return sparseTable[0][start];
  if(start > end) swap(start, end);
  int log = log_2(end - start + 1);
  end -= 1 << (log - 1);
  return func(sparseTable[log][start], sparseTable[log][end]);
}
