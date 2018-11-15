/*
Read N
For N test cases
	Read C, T
	Calculate F
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numTests;
	cin >> numTests;
	while(N--){
		lld capacity, time;
		cin >> capacity >> time;
		long double t = T, f, n = time - 1;
		n = n * (n + 1) / 2;
		f = (capacity- n) / t;
		f = max(ceil(f), 1.0L);
		lld initalFlow = (lld) f;
		cout << initalFlow << "\n";
	}

	return EXIT_SUCCESS;
}
