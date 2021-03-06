int graph[N + 1][N + 1];
// graph[u][v] = cost from vertex u to vertex v

for(int k = 1; k <= N; k++)
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
