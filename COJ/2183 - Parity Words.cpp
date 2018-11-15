/*
For each test case
	Read in the string
	Check each character if the ASCII is odd or even
	Print Even if the even count is higher
	Print Odd if the odd count is higher
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string word;
	int even, odd;

	getline(cin, word); //Read in T
	while(getline(cin, word)){
		even = odd = 0;
		for(int i = 0; i < word.length(); i++){
			if((((int) word[i]) % 2) == 0) even++;
			else odd++;
			//if(((int) word[i]) & 1) odd++;
			//else even++;
		}
		if(even > odd) cout << "Even\n";
		else cout << "Odd\n";
	}

	return EXIT_SUCCESS;
}
