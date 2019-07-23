int A[N + 1], sums[N + 1];

//Building the prefix sum array from the original numbers
sums[i] = A[i]               if i = 1
          A[i] + sums[i - 1] if i > 1

//Queries
query[pos] = sums[pos]
query[start, end] = sums[end] - sums[start - 1]
