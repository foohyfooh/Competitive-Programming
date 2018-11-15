/*
Read N and the string
Find the length L of the Longest Common Subsequence of the string and the reverse of the string
Print N - L
*/
#include <iostream>
#include <string>
using namespace std;

const int MAX_LENGTH = 5000;
int L[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int length;
	string word, reverse;
	cin >> length >> word;
	word = " " + word;

	for(int i = 1; i <= length; i++)
		for(int j = length, k = 1; k <= length; j--, k++)
			if(word[i] == word[j]) L[i][k] = L[i - 1][k - 1] + 1;
			else L[i][k] = max(L[i][k - 1], L[i - 1][k]);
	cout << (length - L[length][length]);

	return EXIT_SUCCESS;
}
