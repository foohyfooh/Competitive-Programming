/*
Longest Common Subsequence is a possible solution. Didn't use that since the lengths were not specified.

Go through the each characters of T and if it matches a character the current in S. Repeat with the next character of S.
If the count of matched characters is equal to the length of S then print Yes else No
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S, T;
	while(cin >> S >> T){
		int s = 0;
		for(int i = 0; i < T.length(); i++)
			if(T[i] == S[s]) s++;
		cout << (s == S.length() ? "Yes" : "No") << endl;
	}

	return EXIT_SUCCESS;
}
