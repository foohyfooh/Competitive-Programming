/*
For each test case
	If A and B result in C by an operation, return YES else return NO
*/
#include <iostream>
using namespace std;

int main(int argc, char** argv){

	int T, A, B, C;
	for(cin >> T; T > 0; T--){
		cin >> A >> B >> C;
		if((A + B) == C) cout << "YES\n";
		else if((A - B) == C) cout << "YES\n";
		else if((A * B) == C) cout << "YES\n";
		else if(B != 0 && (A / B) == C) cout << "YES\n";
		else if(B != 0 && (A % B) == C) cout << "YES\n";
		else cout << "NO\n";
	}

	return EXIT_SUCCESS;
}
