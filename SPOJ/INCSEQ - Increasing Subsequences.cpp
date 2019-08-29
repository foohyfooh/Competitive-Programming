/*
Read N, K
For each number in S
  Read the number, Si
  Add 1 to the count of tuple size 1 for Si
  For each k upto K
    The number of increasing sequnces of size k is the sum of counts of size k-1 for Si-1
      i.e. the number of sequnces that I can extend
    Use a binary index tree to quickly compute the sum
      The positions in the tree are the value of Si
      Thus tree[k][Si] has the sums for [tree[k][1], tree[k][Si - 1]]
The range is shifted up by 1 since zero is a valid value for Si
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_NUMS = 10000;
const int MAX_VALUE = 100000;
const int MAX_TUPLE_LEN = 50;
const int MOD = 5000000;

int increasingSequencesLengths[MAX_TUPLE_LEN + 5][MAX_VALUE + 5];
void update(int tupleSize, int pos, int val){
  for (; pos <= MAX_VALUE; pos += pos & -pos){
    increasingSequencesLengths[tupleSize][pos] += val;
    if (increasingSequencesLengths[tupleSize][pos] >= MOD)
      increasingSequencesLengths[tupleSize][pos] -= MOD;
  }
}

int query(int tupleSize, int pos){
  int sum = 0;
  for (; pos > 0; pos -= pos & -pos){
    sum += increasingSequencesLengths[tupleSize][pos];
    if (sum >= MOD) sum -= MOD;
  }
  return sum;
}

int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int length, tupleSize, num, max = 0;
  cin >> length >> tupleSize;

  for(int i = 0; i < length; i++) {
    cin >> num;
    num++;
    if(num > max) max = num;
    update(1, num, 1);
    for(int k = 2; k <= tupleSize; k++){
      update(k, num, query(k - 1, num - 1));
    }
  }
  cout << query(tupleSize, max) << "\n";

  return EXIT_SUCCESS;
}
