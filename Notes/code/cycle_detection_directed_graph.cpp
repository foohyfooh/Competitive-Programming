#include <vector>

vector<int> adj[N + 1];
bool visited[N + 1], path[N + 1];

bool dfs(int v){
  if(!visited[v]) {
    visited[v] = path[v] = true;
    for(int i: adj[v]){
      if (!visited[i] && dfs(i)) return true;
      else if (path[i]) return true;
    }
  }
  path[v] = false;
  return false;
}

bool isCyclic(){
  for(int i = 1; i <= N; i++)
    if (dfs(i)) return true;
  return false;
}
