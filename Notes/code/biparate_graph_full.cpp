#include <queue>

bool graph[N + 1][N + 1];
VertexColour colour[N + 1]; //Initialize to GREY

bool bipartite(){
  for(int src = 1; i <= N; i++){
    if(colour[src] != GREY) continue;
    queue<int> Q;
    Q.push(src);
    colour[src] = WHITE;
    while(!Q.empty()){
      int u = Q.front(); Q.pop();
      if(graph[u][u]) return false;
      for(int v = 1; v <= N; v++){
        if(graph[u][v])
          if(colour[v] == GREY){
            colour[v] = colour[u] == WHITE ? BLACK : WHITE;
            Q.push(v);
          }else if(colour[u] == colour[v]) return false;
      }
    }
  }
  return true;
}
