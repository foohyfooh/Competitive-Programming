/*
Read N
Read all values of T
Sort T
Assume the list is circular and find the min of each pair next to each other
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_NUMS = 1000;
array<int, MAX_NUMS> zones;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numValues;
	cin >> numValues;
	for(int i = 0; i < numValues; i++) cin >> zones[i];

	sort(zones.begin(), zones.begin() + numValues);

	int sum1 = 0;
	for(int i = 0, end = numValues / 2; i < end; i++)
		sum1 += min(zones[2 * i + 1] - zones[2 * i], 24 - zones[2 * i + 1] + zones[2 * i]);

	int sum2 = min(zones[numValues - 1] - zones[0], 24 - zones[numValues - 1] + zones[0]);
	for(int i = 1, end = numValues / 2; i < end; i++)
		sum2 += min(zones[2 * i] - zones[2 * i - 1], 24 - zones[2 * i] + zones[2 * i - 1]);

	cout << min(sum1, sum2);

	return EXIT_SUCCESS;
}
