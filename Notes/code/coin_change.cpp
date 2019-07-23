//2D Coin Change
int coins[N + 1];
int change[N][K + 1]; //Initialised to INT_MAX

for(int i = 1; i <= N; i++)
		for(int j = 1; j <= K; j++)
			if(j <= coins[i]) change[i][j] = change[i - 1][j];
			else change[i][j] = min(change[i - 1][j], change[i][j - coins[i]] + 1);

//1D Coin Change
int coins[N + 1];
int change[K + 1]; //Initialised to INT_MAX

for(int i = 1; i <= N; i++)
		for(int j = 1; j <= K; j++)
			if(j >= coins[i]) change[j] = min(change[j], change[j - coins[i]] + 1);

//2D Coin Change
int coins[N + 1];
int change[N][K + 1]; //Initialised to INT_MAX

for(int i = 1; i <= N; i++)
		for(int j = coins[i]; j <= K; j++)
			change[i][j] = min(change[i - 1][j], change[i][j - coins[i]] + 1);

//1D Coin Change
int coins[N + 1];
int change[K + 1]; //Initialised to INT_MAX

for(int i = 1; i <= N; i++)
		for(int j = coins[i]; j <= K; j++)
			change[j] = min(change[j], change[j - coins[i]] + 1);
