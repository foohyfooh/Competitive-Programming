/*
Read in the heights of the cows
Determine the shortest and tallest using Square Root Decomposition
For each query print the difference between the shortest and tallest
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define set(A, N, v) for(int i = 0; i < N; i++) A[i] = v;

constexpr int MAX_COWS = 50000;
constexpr int MAX_SQRT = (int) ceil(sqrt(MAX_COWS));
const int TALLEST_SIZE = 1000000;
const int INF  = TALLEST_SIZE + 1;
const int NINF = 0; //-INF;
int heights[MAX_COWS];
int shortest[MAX_SQRT];
int tallest[MAX_SQRT];

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

template<typename F>
int query(int start, int end, int _sqrt, F comp, int val, int computed[MAX_SQRT]){
	int L = start / _sqrt, R = end / _sqrt;
	if(L == R)
		for(int i = start; i <= end; i++) val = comp(val, heights[i]);
	else{
		//Firt Partial Block
		for(int i = start, j = ((L + 1) * _sqrt) - 1; i <= j; i++) val = comp(val, heights[i]);
		//Whole Blocks
		for(int i = L + 1; i <= R - 1; i++) val = comp(val, computed[i]);
		//Last Partial Block
		for(int i = R * _sqrt; i <= end; i++) val = comp(val, heights[i]);
	}
	return val;
}

#define q(f, i, B) query(start - 1, end - 1, _sqrt, f, i, B)

int main(int argc, char** argv){

	int numCows, numQueries, _sqrt, sqrtp, p;
	scanf("%d%d", &numCows, &numQueries);
	_sqrt = ((int) sqrt(numCows)) + 1;

	set(shortest, MAX_SQRT, INF);
	set(tallest, MAX_SQRT, NINF);
	for(int i = 0; i < numCows; i++){
		scanf("%d", &heights[i]);
		p = i / _sqrt;
		shortest[p] = min(shortest[p], heights[i]);
		tallest[p]  = max(tallest[p], heights[i]);
	}

	int start, end, diff;
	while(numQueries--){
		scanf("%d%d", &start, &end);
		diff = q(max, NINF, tallest) - q(min, INF, shortest);
		printf("%d\n", diff);
	}

	return EXIT_SUCCESS;
}
