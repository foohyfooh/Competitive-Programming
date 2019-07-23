#include <cmath>

int A[N], B[N];
SQRT = sqrt(N) + 1;

//Building
for(int i = 0; i < N; i++)
	B[i / SQRT] += A[i];

//Updatting
int update(int pos, int val){
	B[i / SQRT] += val - A[pos];
	A[pos] = val;
}


//Querying
int query(int start, int end){
	int total = 0;
	int L = start / SQRT, R = end / SQRT;

	if(L == R)
		for(int i = start; i <= end; i++) total += A[i];
	else{
		//Firt Partial Block
		for(int i = start; i < (L+1) * SQRT; i++) total += A[i];

		//Whole Blocks
		for(int i = L + 1; i < R; i++) total += B[i];

		//Last Partial Block
		for(int i = R * SQRT; i <= end; i++) total += A[i];
	}

	return total;
}
