/*
Coin Change Problem using the coins 1, 3, 5, 6
*/
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <array>
using namespace std;

const int NUM_COINS = 4;
const int MAX_COIN = 100000;

int coins[] = {1, 3, 5, 6};
array<int, MAX_COIN + 1> change;

int main(int argc, char** argv){

	int numTests, coin, max = 0;
	change.fill(INT_MAX);
	change[0] = 0;

	scanf("%d", &numTests);
	for(int t = 1; t <= numTests; t++){
		scanf("%d", &coin);
		if(coin > max){
			for(int i = 0; i < NUM_COINS; i++)
				for(int j = max + 1; j <= coin; j++){
					if(j >= coins[i]) change[j] = min(change[j], change[j - coins[i]] + 1);
				}

			max = coin;
		}
		printf("Case %d: %d\n", t, change[coin]);
	}

	return EXIT_SUCCESS;
}
