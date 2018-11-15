/*
Read N, U, Q

Use Binary Indexed Tree (Fenwick Tree)
	Keep track of the sums for all additions
	Computing the sum relies on going up the tree
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

constexpr int MAX_CELLS = 1000000, MAX = MAX_CELLS + 2;
constexpr int MOD = 10000;
int values[MAX];

void update(int pos, int max, int val){
	if(pos < 1 || pos > max) return;
	val %= MOD;
	for(; pos <= max; pos += pos & -pos)
		values[pos] = (values[pos] + val) % MOD;
}

int query(int pos){
	int sum = 0;
	for(; pos > 0; pos -= pos & -pos)
		sum = (sum + values[pos]) % MOD;
	return sum;
}

int rangeQuery(int start, int end){
	return (query(end) + MOD - query(start - 1)) % MOD;
}

int main(int argc, char** argv) {
	int numCells, numUpdates, numQuestions, operation, op1, op2;

	scanf("%d%d%d", &numCells, &numUpdates, &numQuestions);
	for(int numLines = numUpdates + numQuestions; numLines > 0; numLines--){
		scanf("%d%d%d", &operation, &op1, &op2);
		if(operation == 1){
			update(op1 - 1, numCells, op2);
			update(op1, numCells, 2 * op2);
			update(op1 + 1, numCells, op2);
		}else//operation == 2
			printf("%d\n", rangeQuery(op1, op2));
	}

	return EXIT_SUCCESS;
}
