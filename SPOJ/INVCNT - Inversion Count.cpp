/*
Read t
For t test cases
  Read n
  Read n numbers in to A[1 .. n]
  Make a sorted copy of the numbers
  Use a Fenwick tree to query the count of a numbers upto a position
  The inversion count of a number would be the total number of elements - the count of the elements upto the desired number
  Print the total count
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;

const int MAX_NUMS = 200000;
// const int MAX_VALUE = 1e7;
array<int, MAX_NUMS + 5> nums, sortedNums;
array<llu, MAX_NUMS + 5> tree;

int cmp(const void* a, const void* b){
  return (*(int*)a) - (*(int*)b);
}

void update(int pos, int size, int val){
  for (; pos <= size; pos += pos & -pos)
    tree[pos] += val;
}

int query(int pos){
  int sum = 0;
  for (; pos > 0; pos -= pos & -pos)
    sum += tree[pos];
  return sum;
}

int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int numTests;
  for(cin >> numTests; numTests > 0; numTests--){
    int numNums;
    cin >> numNums;

    nums.fill(0);
    tree.fill(0);
    for(int i = 1; i <= numNums; i++){
      cin >> nums[i];
      sortedNums[i] = nums[i];
    }
    sort(sortedNums.begin() + 1, sortedNums.begin() + numNums + 1);

    llu count = 0;
    for(int i = 1; i <= numNums; i++){
      int* ptr = (int*)bsearch(&nums[i], sortedNums.cbegin() + 1, numNums, sizeof(int), cmp);
      int pos = ptr - sortedNums.cbegin();
      count += query(numNums) - query(pos);
      update(pos, numNums, 1);
    }
    cout << count << "\n";
  }

  return EXIT_SUCCESS;
}
