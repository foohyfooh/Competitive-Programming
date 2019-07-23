#include <vector>

template<typename T>
struct Tree{
  T data;
  vector<int> adj;
}

void addEdge(Tree tree[N], int from, int to){
  tree[from].adj.push_back(to);
  tree[to].adj.push_back(from);
}
