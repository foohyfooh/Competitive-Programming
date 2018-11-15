/*
For each test case
	Read in the string
	Count the occurances of each character
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 100;
string word;
int count[26];

int main(int argc, char** argv){

	int numTests;
	for(scanf("%d", &numTests); numTests > 0; numTests--){
		memset(count, 0, sizeof(count));
		cin >> word;
		int i = 0;
		while(word[i] != '\0'){
			int pos = (int) word[i] - 'A';
			count[pos]++;
			i++;
		}
		if(count['B'- 'A'] == count['R' - 'A'] && count['R' - 'A'] == count['O' - 'A']
			&& count['O' - 'A'] == count['K' - 'A'] && count['K' - 'A'] == count['E' - 'A']
			&& count['E' - 'A'] == count['N' - 'A']) cout << "No ";
		cout << "Secure\n";
	}

	return EXIT_SUCCESS;
}
