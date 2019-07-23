#include <array>

typedef long long int lld;
typedef array<lld, N> arr;
typedef array<arr, N> mat;
const mat I{};

void fillI(){
	for(int i = 0; i < N; i++) I[i][i] = 1;
}

mat matMul(mat A, mat B){
	mat C{};
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
	return C;
}

mat matPow(mat A, lld b){
	if(b == 0) return I;
	if(b == 1) return A;
	mat R = matPow(A, b / 2);
	R = matMul(R, R);
	return b % 2 == 0 ? R : matMul(A, R);
}
