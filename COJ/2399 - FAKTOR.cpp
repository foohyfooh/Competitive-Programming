/*
Read A, I
The min number of scientists to bribe is the first number greater than A * (I - 1)
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int numArticles, impactFactor, minScientists;
  cin >> numArticles >> impactFactor;
  minScientists = numArticles * (impactFactor - 1) + 1;
  cout << minScientists;

  return EXIT_SUCCESS;
}
