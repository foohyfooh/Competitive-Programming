//2D 0/1 Knapsack
int weights[N + 1];
int values[N + 1];
int knapsack[N + 1][W + 1];

for(int i = 1; i <= N; i++){
	for(int j = 1; j <= N; j++){
		if(i == 1 && weights[i] > j) knapsack[i][j] = knapsack[i][j - 1];
		else if(weights[i] > j) knapsack[i][j] = knapsack[i - 1][j];
		else knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i - 1][j - weights[i]] + values[i]);
	}
}

//1D 0/1 Knapsack
int weights[N + 1];
int values[N + 1];
int knapsack[W + 1];

for(int i = 1; i <= N; i++){
	for(int j = 1; j <= N; j++){
		if(weights[i] > j) knapsack[j] = knapsack[j - 1];
		else knapsack[j] = max(knapsack[j], knapsack[j - weights[i]] + values[i]);
	}
}

//2D Unbounded Knapsack
int weights[N + 1];
int values[N + 1];
int knapsack[N + 1][W + 1];

for(int i = 1; i <= N; i++){
	for(int j = 1; j <= N; j++){
		if(i == 1 && weights[i] > j) knapsack[i][j] = knapsack[i][j - 1];
		else if(weights[i] > j) knapsack[i][j] = knapsack[i - 1][j];
		else knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i][j - weights[i]] + values[i]);
	}
}

//1D Unbounded Knapsack
int weights[N + 1];
int values[N + 1];
int knapsack[W + 1];

for(int i = 1; i <= N; i++){
	for(int j = 1; j <= N; j++){
		if(weights[i] > j) knapsack[j] = knapsack[j - 1];
		else knapsack[j] = max(knapsack[j], knapsack[j - weights[i]] + values[i]);
	}
}
