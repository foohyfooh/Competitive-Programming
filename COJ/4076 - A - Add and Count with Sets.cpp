/*
Read Q
For Q lines
	Read op
	If op == 1
		Insert x in order
	If op == 2
		Check the lower bound, x and upper bound, y
		Print the distance between the bounds
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numQueries, op;
	int x, y;
	cin >> numQueries;
	while(numQueries--){
		cin >> op;
		if(op == 1){
			cin >> x;
			nums.insert(upper_bound(nums.begin(), nums.end(), x), x);
		}else{ //op == 2
			cin >> x >> y;
			auto s = lower_bound(nums.begin(), nums.end(), x);
			auto e = upper_bound(nums.begin(), nums.end(), y);
			cout << distance(s, e) << "\n";
		}
	}

	return EXIT_SUCCESS;
}
