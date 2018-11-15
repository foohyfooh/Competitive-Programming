/*
Read in the string
Keep a count of each time every 8 character substring appears in the string
Print the one with the highest count that is lexicographically lower
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;

const int CHECK_LENGTH = 8;
string s, sub;
map<string, int> counts;
typedef pair<string, int> psi;
auto cmp = [](psi a, psi b){
	if(a.second == b.second) return a.first > b.first;
	return a.second < b.second;
};
priority_queue<psi, vector<psi>, decltype(cmp)> Q(cmp);

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	for(int i = 0; (i + CHECK_LENGTH) <= s.length(); i++){
		sub = s.substr(i, CHECK_LENGTH);
		counts[sub]++;
	}
	for(auto m: counts) Q.push(make_pair(m.first, m.second));
	psi top = Q.top();
	if(top.second < 2) cout << "Solution was not found";
	else cout << top.first;

	return EXIT_SUCCESS;
}
