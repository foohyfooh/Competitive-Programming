/*
Naive Solution
  Have an array and update the values in the ranges [l, r] with v in O(n)
  Queries would be in O(1) as it would be an index lookup

Use binary index tree to store values to have O(log n) updates and lookup
Read t
For t test cases
  Read n, u
  For u updates
    Read l, r, v
    Update [l, r] with v
    Update [r + 1, n] with -v

    This results in the indexes that are powers of 2 having +ve numbers and the others having -ve values
    When the sum at an index is calculated the negative values will give the value at that position

  Read q
  For q queries
    Read index
    Read the sum
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_NUMS = 10000;
array<int, MAX_NUMS + 1> nums;

void update(int start, int end, int val){
  for(; start <= end; start += start & -start)
    nums[start] += val;
}

int query(int pos){
  int s = 0;
  for(; pos > 0; pos -= pos & -pos)
    s += nums[pos];
  return s;
}

int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int numTestCases, numNums, numUpdates, numQueries, pos;
  cin >> numTestCases;

  while(numTestCases--){
    cin >> numNums >> numUpdates;

    int start, end, val;
    while(numUpdates--){
      cin >> start >> end >> val;
      start++, end++;
      update(start, numNums, val);
      update(end + 1, numNums, -val);
    }

    int pos;
    cin >> numQueries;
    while(numQueries--){
      cin >> pos;
      cout << query(pos + 1) << "\n";
    }

    nums.fill(0);
  }

  return EXIT_SUCCESS;
}
