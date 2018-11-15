/*
Determine the number of even and odd
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {

	int t, n, val, even, odd;
	for(cin >> t; t > 0; t--){
		even = odd = 0;
		for(cin >> n; n > 0; n--){
			cin >> val;
			if(val % 2 == 0) even++;
			else odd++;
		}
		cout << even << " even and " << odd << " odd.\n";
	}

	return EXIT_SUCCESS;
}
