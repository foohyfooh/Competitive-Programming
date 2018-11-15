/*
Summation upto fib(N) + 1 == fib(N + 2)
For each test case
	Use Matrix Exponentiation to calculate fib(N + 2)
	Print fib(N + 2)
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int lld;

const int MOD = 1000007;
lld T[2][2] = {{0, 1}, {1, 1}}, C[2][2], temp[2][2];

void matMul(lld A[2][2], lld B[2][2]){
	temp[0][0] = ((A[0][0] * B[0][0]) % MOD + (A[0][1] * B[1][0]) % MOD) % MOD;
	temp[0][1] = ((A[0][0] * B[0][1]) % MOD + (A[0][1] * B[1][1]) % MOD) % MOD;
	temp[1][0] = ((A[1][0] * B[0][0]) % MOD + (A[1][1] * B[1][0]) % MOD) % MOD;
	temp[1][1] = ((A[1][0] * B[0][1]) % MOD + (A[1][1] * B[1][1]) % MOD) % MOD;
	memcpy(C, temp, sizeof(C));
}

void matPow(lld A[2][2], lld b){
	if(b == 1) {
		memcpy(C, A, sizeof(C));
		return;
	}
	matPow(A, b / 2);
	matMul(C, C);
	if(b % 2 != 0) matMul(A, C);
}

lld fib(lld N){
	if(N == 0) return 1;
	matPow(T, N);
	return (C[0][0] + C[0][1] + C[0][1]) % MOD;
}

int main(int argc, char** argv){

	int numTests;
	lld N;
	for(scanf("%d", &numTests); numTests > 0; numTests--){
		scanf("%lld", &N);
		printf("%lld\n", fib(N));
	}

	return EXIT_SUCCESS;
}
