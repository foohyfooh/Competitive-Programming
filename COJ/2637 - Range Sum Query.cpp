/*
Read t
For each test case
	Read n, q
	Read in the n numbers
	Compute the prefix sum
	For each query(i, j) print (sum[j] - sum[i - 1])
*/
#include <cstdio>
#include <cstdlib>
//#include <algorithm>
using namespace std;

const int MAX_NUMS = 100000;
unsigned long long int nums[MAX_NUMS];

int main(int argc, char** argv){

	int numTests, numNums, numQueries, start, end;
	scanf("%d", &numTests);
	while(numTests--){
		scanf("%d%d", &numNums, &numQueries);

		scanf("%d", &nums[0]);
		for(int i = 1; i < numNums; i++){
			scanf("%llu", &nums[i]);
			nums[i] += nums[i - 1];
		}

		while(numQueries--){
			scanf("%d%d", &start, &end);
			//if(start > end) swap(start, end);
			printf("%llu\n", nums[end] - (start != 0 ? nums[start - 1] : 0));
		}

		if(numTests != 0) printf("\n");
	}

	return EXIT_SUCCESS;
}
