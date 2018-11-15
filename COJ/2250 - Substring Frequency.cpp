/*
For each test
	Read in the A and B
	Do KMP and count the number of matches
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX_LENGTH = 1000000;
int P[MAX_LENGTH + 1];

void computePrefix(string pattern, int size){
	memset(P, 0, sizeof(P)), P[0] = -1, P[1] = 0;
	int k = 0;
	for(int i = 2; i <= size; i++){
		while(k > 0 && pattern[k + 1] != pattern[i]) k = P[k];
		if(pattern[k + 1] == pattern[i]) k++;
		P[i] = k;
	}
}

int kmp(string text, string pattern){
	int N = text.size(), M = pattern.size();
	text = " " + text, pattern = " " + pattern;
	computePrefix(pattern, M);
	int count = 0;
	for(int i = 1, q = 0; i <= N; i++){
		while(q > 0 && pattern[q + 1] != text[i]) q = P[q];
		if(pattern[q + 1] == text[i]) q++;
		if(q == M){
			count++;
			q = P[q];
		}
	}
	return count;
}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numTests;
	cin >> numTests;
	for(int t = 1; t <= numTests; t++){
		string text, pattern;
		cin >> text >> pattern;
		cout << "Case " << t << ": " << kmp(text, pattern) << endl;
	}

	return EXIT_SUCCESS;
}
