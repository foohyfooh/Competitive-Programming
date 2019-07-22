/*
Read T
For T test cases
	Read N
	Print if N is divisible by 4 i.e. if the last two digits are divisible by 4
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numTests, num, len;
	string numberStr;
	cin >> numTests;
	for(int i = 0; i < numTests; i++) {
		cin >> numberStr;
		len = numberStr.length();
		if(len < 2){
			num = stoi(numberStr);
		}else{
			num = stoi(numberStr.substr(len - 2), 0);
		}
		cout << (num % 4 == 0 ? "YES" : "NO") << "\n";
	}

	return EXIT_SUCCESS;
}
