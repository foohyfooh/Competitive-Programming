/*
Read a, b, c
Read d, e, f
Read C
Read next C line
	Read N
	Use Matrix Exponentiation to calculate f[N]
	Print f[N]
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

const int MAX_N = 1e9;
const lld MOD = 1000000007;

const int dim = 6;
typedef array<lld, dim> arr;
typedef array<arr, dim> mat;

int a, b, c, d, e, f, C, N;

mat matMul(mat A, mat B){
	mat C{};
	for(int i = 0; i < dim; i++)
		for(int j = 0; j < dim; j++)
			for(int k = 0; k < dim; k++)
				C[i][j] = (C[i][j] +  (A[i][k] * B[k][j]) % MOD) % MOD;
	return C;
}

mat matPow(mat A, lld b){
	if(b == 1) return A;
	mat R = matPow(A, b / 2);
	R = matMul(R, R);
	return b % 2 == 0 ? R : matMul(A, R);
}

lld calcF(int N){
	if(N == 0) return 0;
	if(N == 1) return 1;
	mat T = {arr{a, 0, 0, b, 1, 0}, arr{1, 0, 0, 0, 0, 0}, arr{0, 0, d, e, 0, 1}, arr{0, 0, 1, 0, 0, 0}, arr{0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}};
	mat R = matPow(T, N - 1);
	lld result = R[0][0];
	//result = (result + R[0][1] * 0) % MOD;
	result = (result + R[0][2]) % MOD;
	//result = (result + R[0][3] * 0) % MOD;
	result = (result + R[0][4] * c) % MOD;
	result = (result + R[0][5] * f) % MOD;
	return result;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b >> c;
	cin >> d >> e >> f;
	cin >> C;
	while(C--){
		cin >> N;
		cout << calcF(N) % MOD << "\n";
	}

	return EXIT_SUCCESS;
}
