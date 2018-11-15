/*
Read N, U, Q
For each line of updates
	Use modulo arithmetic during the additions since the (a + b) % c == (a % c + b % c)

Use Prefix Sum to calculate the value up to the position i [1, N]
sum[i] = A[i]              if i = 1
         A[i] + sum[i - 1] if i > 1

For each question
	Return (sum[u] to sum[v]) % 10^4
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

constexpr int MAX_CELLS = 1000000;
constexpr int MAX = MAX_CELLS + 2;
constexpr int MOD = 10000;
int values[MAX];

int main(int argc, char** argv) {
	int numCells, numUpdates, numQuestions, pos, updateVal, start, end, total;

	scanf("%d%d%d", &numCells, &numUpdates, &numQuestions);
	for(; numUpdates > 0; numUpdates--){
		scanf("%d%d", &pos, &updateVal);
		values[pos - 1] = (values[pos - 1] + updateVal % MOD) % MOD;
		values[pos] = ((values[pos] + (updateVal + 1) % MOD)) % MOD;
		values[pos + 1] = (values[pos + 1] + updateVal % MOD) % MOD;
	}
	values[0] = 0;
	for(int i = 2; i <= numCells; i++) values[i] = (values[i - 1] + values[i]) % MOD;

	for(; numQuestions > 0; numQuestions--){
		scanf("%d%d", &start, &end);
		total = (values[end] + MOD - values[start - 1]) % MOD;
		printf("%d\n", total);
	}

	return EXIT_SUCCESS;
}
