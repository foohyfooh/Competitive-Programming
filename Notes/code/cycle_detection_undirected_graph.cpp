#include <vector>

vector<int> adj[N + 1];
bool visited[N + 1];

bool dfs(int v, int parent = 0){
  visited[v] = true;
  for (int i: adj[v]){
    if (!visited[i] && dfs(i, v)) return true;
    else if (visited[i] && i != parent) return true;
  }
  return false;
}

bool isCyclic() {
  for (int u = 1; u <= N; u++)
    if (!visited[u] && dfs(u)) return true;
  return false;
}
