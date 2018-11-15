/*
Read N
Read all the numbers Ni
Sort the numbers
Print the numbers
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_NUMS = 1000;
int nums[MAX_NUMS];

int main(int argc, char** argv){

	int numNums;
	scanf("%d", &numNums);
	for(int i = 0; i < numNums; i++) scanf("%d", &nums[i]);
	sort(nums, nums + numNums);
	for(int i = 0; i < numNums; i++) printf("%d\n", nums[i]);

	return EXIT_SUCCESS;
}