/*
Determining if numbers are a multiple of 11
A number is divisible by 11 if the alternating sum of all the digits is a multiple of 11
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//const int MAX_LENGTH = 1000;

int main(int argc, char** argv){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string num;
	int sum;

	for(cin >> num; num != "0"; cin >> num){
		sum = 0;
		for(int i = 0; i < num.size(); i += 2) sum = (sum + (num[i] - '0'));
		for(int i = 1; i < num.size(); i += 2) sum = (sum - (num[i] - '0'));
		cout << num << " is ";
		if(sum % 11 != 0) cout << "not ";
		cout << "a multiple of 11.\n";
	}

	return EXIT_SUCCESS;
}
