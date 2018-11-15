/*
Initialize set {0, 1000000}
Read the number to insert
Get the first number that is greater than or equal to that number and display it and the number before that one
*/
#include <cstdio>
#include <cstdlib>
#include <set>
#include <iterator>
using namespace std;

int main(int argc, char** argv){

	int numsToRead, num;
	set<int> nums;
	nums.insert(0);
	nums.insert(1000000);
	scanf("%d", &numsToRead);
	while(numsToRead--){
		scanf("%d", &num);
		auto iter = nums.lower_bound(num);
		printf("%d %d\n", *iter == num ? num : *prev(iter), *iter);
		nums.insert(num);
	}

	return EXIT_SUCCESS;
}
