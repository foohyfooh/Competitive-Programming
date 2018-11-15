/*
Use a Fenwick Tree for the compute the range sum queries
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_NUMS = 100000, MAX = MAX_NUMS + 1;
int sacks[MAX], sums[MAX];

void update(int pos, int max, int val){
	for(; pos <= max; pos += pos & -pos)
		sums[pos] += val;
}

int query(int pos){
	int sum = 0;
	for(; pos > 0; pos -= pos & -pos)
		sum += sums[pos];
	return sum;
}

int main(int argc, char** argv){
	int numTests, numSacks, numQueries, operation, pos, val, start, end;

	scanf("%d", &numTests);
	for(int t = 1; t <= numTests; t++){
		printf("Case %d:\n", t);

		scanf("%d%d", &numSacks, &numQueries);
		memset(sacks, 0, sizeof(sacks));
		memset(sums, 0, sizeof(sums));
		for(int i = 1; i <= numSacks; i++){
			scanf("%d", &sacks[i]);
			update(i, numSacks, sacks[i]);
		}

		while(numQueries--){
			scanf("%d", &operation);
			if(operation == 1){
				scanf("%d", &pos), pos++;
				printf("%d\n", sacks[pos]);
				update(pos, numSacks, -sacks[pos]);
				sacks[pos] = 0;
			}else if(operation == 2){
				scanf("%d%d", &pos, &val), pos++;
				sacks[pos] += val;
				update(pos, numSacks, val);
			}else{ //operation == 3
				scanf("%d%d", &start, &end);
				printf("%d\n", query(end + 1) - query(start));
			}
		}
	}

	return EXIT_SUCCESS;
}
