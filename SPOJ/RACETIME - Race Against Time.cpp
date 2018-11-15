/*
Read N and Q

Read the N initial values of the cows

Read in the Q operations
	If 'M i X' Then change the ith's cows value to X
	If 'C P Q X' Then count the number of cows with a value less than or equal to x

Use sqrt decomposition
Each block is a sorted vector of the items in that block
*/
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

//constexpr int MAX_COWS = 1e5;
//constexpr int MAX_SQRT = (int) ceil(sqrt(MAX_COWS));
//constexpr int MAX_SIGN = 1e9;
//constexpr int MAX_OPERATIONS = 5e4;
constexpr int MAX_COWS = 1e5;
constexpr int MAX_SQRT = 320;

int cows[MAX_COWS + 5];
vector<int> blocks[MAX_SQRT];

void update(int pos, int value, int _sqrt){
	int blockPos = pos / _sqrt;
	vector<int> block = blocks[blockPos];
	auto iter = lower_bound(block.begin(), block.end(), cows[pos]);
	*iter = value;
	sort(block.begin(), block.end());
	blocks[blockPos] = block;
	cows[pos] = value;
}

int query(int start, int end, int _sqrt, int max){
	int L = start / _sqrt, R = end / _sqrt, count = 0;
	if(L == R) {// In the same block
		for(int i = start; i <= end; i++)
		if(cows[i] <= max) count++;
	}else{
		for(int i = start, e = ((L + 1) * _sqrt) - 1; i <= e; i++)
			if(cows[i] <= max) count++;
		for(int i = L + 1; i < R; i++){
			auto iter = upper_bound(blocks[i].begin(), blocks[i].end(), max);
			//count += distance(blocks[i].begin(), iter);
			count += iter - blocks[i].begin();
		}
		for(int i = R * _sqrt; i <= end; i++)
			if(cows[i] <= max) count++;
	}
	return count;
}

int main(int argc, char** argv) {

	int numCows, numOperations, _sqrt;
	scanf("%d%d", &numCows, &numOperations);
	_sqrt = ((int) sqrt(numCows)) + 1;
	for(int i = 0; i < numCows; i++) {
		scanf("%d", &cows[i]);
		blocks[i / _sqrt].push_back(cows[i]);
	}
	for(int i = 0; i <= _sqrt; i++) sort(blocks[i].begin(), blocks[i].end());

	char op[2];
	int pos, start, end, value;
	while(numOperations--){
		scanf("%s", op);
		if (op[0] == 'M') {
			scanf("%d%d", &pos, &value);
			update(pos - 1, value, _sqrt);
		}else{ //op[0] == 'C'
			scanf("%d%d%d", &start, &end, &value);
			printf("%d\n", query(start - 1, end - 1, _sqrt, value));
		}
	}

	return EXIT_SUCCESS;
}
