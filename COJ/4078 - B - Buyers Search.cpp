/*
Read N
Read all N values of C
Read H
For next H lines
	Read P, A, B
	Check for the range [A, B]  for the first person who can purchase the house
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_BUYERS = 1e5, MAX_HOUSES = 1e5;
array<int, MAX_BUYERS + 5> money, blocks;

int findPos(int start, int end, int cost){
	for(int i = start; i <= end; i++){
		if(money[i] >= cost){
			return i;
		}
	}
	return -1;
}

int query(int start, int end, int _sqrt, int cost){
	int L = start / _sqrt, R = end / _sqrt;
	if(L == R){
		if(blocks[L] >= cost)
			return findPos(start, end, cost);
		return -1;
	}else{
		int p = findPos(start, (L + 1) * _sqrt, cost);
		if(p != -1) return p;
		for(int i = L + 1; i < R; i++){
			if(blocks[i] >= cost) {
				int s = i * _sqrt, e = s + _sqrt;
				return findPos(s, e, cost);
			}
		}
		return findPos(R * _sqrt, end, cost);
	}
}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numBuyers, m = 1, _sqrt;
	cin >> numBuyers;
	_sqrt = (int) sqrt(numBuyers) + 1;
	for(int i = 1; i <= numBuyers; i++) {
		cin >> money[i];
		if(money[i] > money[m]) m = i;
		int p = i / _sqrt;
		blocks[p] = max(money[i], blocks[p]);
	}

	int numHouses;
	cin >> numHouses;
	int price, start, end;
	while(numHouses--){
		cin >> price >> start >> end;
		int p = -1;
		if(price <= money[m]) p = query(start, end, _sqrt, price);
		cout << p << "\n";
	}

	return EXIT_SUCCESS;
}
