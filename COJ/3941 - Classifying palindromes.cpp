/*
For each word
	If it is palindrome; If so print palindrome
	If not check every split for being two palindromes; If so print bi-palindrome
	Else print non-palindrome

*/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word){
	bool isPalindrome = true;
	for(int i = 0, j = word.length() - 1; isPalindrome && i <= j; i++, j--)
		isPalindrome &= word[i] == word[j];
	return isPalindrome;
}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numWords;
	for(cin >> numWords; numWords > 0; numWords--){
		string word;
		cin >> word;
		if(isPalindrome(word)){
			cout << "palindrome\n";
			continue;
		}
		for(int split = 1; split < word.size(); split++){
			if(isPalindrome(word.substr(0, split)) && isPalindrome(word.substr(split))){
				cout << "bi-palindrome\n";
				goto end;
			}
		}

		cout << "non-palindrome\n";
		end:;
	}


	return EXIT_SUCCESS;
}
