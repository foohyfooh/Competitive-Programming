/*
Precalculate the divisor summation for all numbers by using the principle of the Eratosthenes
Print the sums in constant time
*/
#include <cstdio>
#include <cstdlib>
#include <array>
using namespace std;

const int MAX_NUMS = 500000;
array<int, MAX_NUMS + 1> solutions;

int main(int argc, char** argv){

	int numTests, num;

	solutions.fill(1);
	solutions[1] = 0;
	for(int i = 2; i < MAX_NUMS; i++){
		for(int j = i + i; j <= MAX_NUMS; j += i){
			solutions[j] += i;
		}
	}

	for(scanf("%d", &numTests); numTests > 0; numTests--){
		scanf("%d", &num);
		printf("%d\n", solutions[num]);
	}

	return EXIT_SUCCESS;
}
