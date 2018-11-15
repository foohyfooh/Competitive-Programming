/*
Precaluclate the Fibonacci Sequence.
For each N, print fib[N - 2], fib[N - 1] and fib[N]
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX_FIB = 10000;
const int MOD = 10000;
int fib[MAX_FIB + 1];

int main(int argc, char** argv){

	fib[1] = fib[2] = 1;
	for(int i = 3; i <= MAX_FIB; i++) fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;

	int numTests, N;
	for(scanf("%d", &numTests); numTests > 0; numTests--){
		scanf("%d", &N);
		printf("%d %d %d\n", fib[N - 2], fib[N - 1], fib[N]);
	}

	return EXIT_SUCCESS;
}
