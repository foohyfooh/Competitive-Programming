/*
Read in the nums and sort them
Read in the order
Print the numbers based on the order
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nums[3];
	string order;

	cin >> nums[0] >> nums[1] >> nums[2];
	sort(nums, nums + 3);
	cin >> order;

	if(order[0] == 'A') cout << nums[0];
	else if(order[0] == 'B') cout << nums[1];
	else /*order[0] == 'C'*/ cout << nums[2];
	cout << " ";

	if(order[1] == 'A') cout << nums[0];
	else if(order[1] == 'B') cout << nums[1];
	else /*order[1] == 'C'*/ cout << nums[2];
	cout << " ";

	if(order[2] == 'A') cout << nums[0];
	else if(order[2] == 'B') cout << nums[1];
	else /*order[2] == 'C'*/ cout << nums[2];

	return EXIT_SUCCESS;
}
