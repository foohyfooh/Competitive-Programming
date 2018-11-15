/*
For each line
	Read A
	Print Y if A is divisible by 6 else N
*/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int angle;
	while(cin >> angle){
		cout << (angle % 6 == 0 ? 'Y' : 'N') << "\n";
	}

	return EXIT_SUCCESS;
}
