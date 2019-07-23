#include <queue>
#include <array>
#include <utility>

Tree tree[N + 1];
queue<int> Q;
array<int, N + 1> dist;

pair<int, int> bfs(int source){
  Q.push(source);
  dist.fill(-1);
  dist[source] = 0;

  while(!Q.empty()){
    int curr = Q.front(); Q.pop();
    vector<int> adj = tree[curr];
    for(int i = 0; i < adj.size(); i++){
      if(dist[adj[i]] == -1){
        Q.push(adj[i]);
        dist[adj[i]] = dist[curr] + 1;
      }
    }
  }

  int max = 1;
  for(int i = 2; i <= N; i++)
    if (dist[i] > dist[max])  max = i;

  return make_pair(max, dist[max]);
}

int longestPath(int source){
  pair<int, int> t1 = bfs(source);
	pair<int, int> t2 = bfs(t1.first);
	return t2.second;
}
