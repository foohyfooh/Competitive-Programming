/*
Read N
Print the count of the numbers in the range [1, N] that are coprime with N
Eliminate multiples of non coprimes to reduce the number of operations
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

const int MAX_NUMS = 1e4;
array<bool, MAX_NUMS + 1> ignored;

bool arecoprime(lld a, lld b){
	if(a > b) swap(a, b);
	lld temp;
	while (a != 0) {
		temp = a;
		a = b % a;
		b = temp;
	}
	return b == 1;
}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	lld num, count = 0;
	cin >> num;
	for(int i = 1; i < num; i++){
		if(!ignored[i]){
			if(arecoprime(i, num)) count++;
			else{
				for(int s = i; s <= num; s += i) ignored[s] = true;
			}
		}
	}
	cout << count;

	return EXIT_SUCCESS;
}

