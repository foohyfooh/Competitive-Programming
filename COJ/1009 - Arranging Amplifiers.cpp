/*
Read T
For T test cases
  Read N
  Read N p values
  Reverse sort the numbers with the exception of 2 and 3. 2 and 3 are sorted normally
  Print the numbers
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_NUMS = 1e5;

auto cmp = [](int a, int b){
  if(a == 1) return false;
  if(b == 1) return true;
  if(a == 2 && b == 3) return false;
  if(a == 3 && b == 2) return true;
  return a < b;
};
priority_queue<int, vector<int>, decltype(cmp)> amps(cmp);

int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int numTests;
  cin >> numTests;
  while(numTests--){
    int numAps, amp;
    cin >> numAps;
    for(int i = 0; i < numAps; i++){
      cin >> amp;
      amps.push(amp);
    }
    while(!amps.empty()){
      amp = amps.top(); amps.pop();
      cout << amp << " ";
    }
    cout << "\n";
  }

  return EXIT_SUCCESS;
}
