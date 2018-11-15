/*
Read in the word
For each character add its position to the sum
Print the sum
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	cin >> word;

	int sum = 0;
	for(int i = 0; i < word.length(); i++) sum += word[i] - 'A' + 1;
	cout << sum;

	return EXIT_SUCCESS;
}
