/*
For each test case
	Read in the number
	Check if it has a minus sign at the start
	Calculate the sum of the digits
	Print the sum
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numTests, sum;
	string num;
	for(cin >> numTests; numTests > 0; numTests--){
		sum = 0;
		cin >> num;
		for(int i = num[0] == '-' ? 1 : 0; i < num.size(); i++) sum += (num[i] - '0');
		cout << sum << endl;
	}

	return EXIT_SUCCESS;
}
