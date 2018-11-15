/*
Read in the number to sort
If the number is positive, sort in increasing order
If the number is negative, sort in descending order
Ensure that the number doesn't start with 0 by moving the first non-zero number to the front
Print the result
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool sortRev(char a, char b){
	return b < a;
}

int main(int argc, char** argv){

	int T;
	string s;
	for(cin >> T; T > 0; T--){
		cin >> s;
		if(s[0] == '-') sort(s.begin() + 1, s.end(), sortRev);
		else sort(s.begin(), s.end());

		int i = 0;
		while(i < s.length() && s[i] == '0'){
			i++;
		}
		if(i < s.length()) swap(s[0], s[i]);
		cout << s << endl;
	}

	return EXIT_SUCCESS;
}
