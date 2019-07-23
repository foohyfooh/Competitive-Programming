#include <vector>

Edge edges[N + 1];
vector<vector<int>> adj;
vector<int> tour, newIndexToOldIndex;
int firstEncounter[N + 1];

void setupAdj(){
  for(Edge e: edges){
    adj[e.from].push_back(e.to);
    adj[e.to].push_back(e.from);
  }
}

void eulerTour(int vertex = 1, int parent = 0){
  int newIndex = newIndexToOldIndex.size();
  newIndexToOldIndex.push_back(vertex);
  firstEncounter[vertex] = tour.size();
  tour.push_back(newIndex);

  for(int u: adj[vertex]){
    if(u == parent) continue;

    eulerTour(u, vertex);
    tour.push_back(newIndex);
  }
}
