/*
Read the string
Compute the prefix function
Calculate the sum for the longest prefix where vowels get a value of 5 and non-vowels get a value of 3
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX_LENGTH = 1000000;
int P[MAX_LENGTH + 1], S[MAX_LENGTH + 1];

#define isVowel(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numTests, max, value, size;
	string word;

	for(cin >> numTests; numTests > 0; numTests--){
		cin >> word;
		size = word.length();
		word = " " + word;
		memset(P, 0, sizeof(P)), P[0] = -1, P[1] = 0;
		memset(S, 0, sizeof(S));

		int k = 0;
		for(int i = 2; i <= size; i++){
			while(k > 0 && word[k + 1] != word[i]) k = P[k];
			if(word[k + 1] == word[i]) k++;
			P[i] = k;
		}

		max = 1, value = 0;
		for(int i = 2; i <= word.size(); i++) if(P[i] > P[max]) max = i;
		for(int i = 1; i <= P[max]; i++)
			value += isVowel(word[i]) ? 5 : 3;
		printf("%d\n", value);
	}

	return EXIT_SUCCESS;
}
