/*
Read the number of beers
Check the conditions
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numBeers;
	cin >> numBeers;
	if(numBeers < 2) cout << "WRONG ANSWER";
	else if(numBeers > 3) cout << "RUNTIME ERROR";
	else cout << "ACCEPTED";

	return EXIT_SUCCESS;
}
