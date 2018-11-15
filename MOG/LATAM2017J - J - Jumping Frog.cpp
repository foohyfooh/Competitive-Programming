/*
Read in S of length N
Count the number of rocks and ponds
If there are no ponds return (N - 1)

Determine the number of divisors of N using Sieve of Eratosthenes
Determine the gcd of each divisors with N and count how much have the same gcd

For each divisor of N
	Start at a point before the divisor
	If you reach a pond then choose the next point before the divisor
	If you reach the end then add the gcd count of that divisor

Return the sum of all the successful divisors
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int gcd(int a, int b){
	int temp;
	while(a != 0){
		temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}

const int MAX_LENGTH = 100000;
char S[MAX_LENGTH + 1];
vector<int> divisors;
int gcds[MAX_LENGTH + 1];

int main(int argc, char** argv){

	int numRocks = 0, numPonds = 0, length, numJumpLengths = 0;
	bool landedInPond;

	scanf("%s", S);
	for(length = 0; S[length] != '\0'; length++)
		if(S[length] == 'R') numRocks++;
		else /*S[length] == 'P'*/ numPonds++;

	if(numPonds == 0) {
		printf("%d\n", length - 1);
		return EXIT_SUCCESS;
	}

	for(int i = 2; i * i <= length; i++){
		if(length % i == 0){
			divisors.push_back(i);
			if(i * i == length) break;
			divisors.push_back(length / i);
		}
	}

	for(int i = 2; i < length; i++)
		gcds[gcd(i, length)]++;

	for(int i = 0; i < divisors.size(); i++){
		for(int j = 0; j < divisors[i]; j++){
			landedInPond = false;
			for(int k = j; k < length && !landedInPond; k += divisors[i])
				landedInPond = S[k] == 'P';
			if(!landedInPond){
				numJumpLengths += gcds[divisors[i]];
				break;
			}
		}
	}

	printf("%d\n", numJumpLengths);

	return EXIT_SUCCESS;
}