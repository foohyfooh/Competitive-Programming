#include <queue>
#include <vector>

void dijkstra(Vertex graph[N], int source){
	auto cmp = [graph](int u, int v) {
		return graph[u].cost < graph[v].cost;
	};
	priority_queue<int, vector<int>, decltype(cmp)> Q(cmp);

	for(int i = 1; i <= N; i++) graph[i].cost = INFINITY;
	graph[source].cost = 0;
	Q.push(source);

	while(!Q.empty()){
		Vertex v = graph[Q.top()]; Q.pop();
		Edge* curr = v.edges;

		while(curr != nullptr){
			int cost = v.cost + curr->weight;
			if(cost < graph[curr->to].cost){
				graph[curr->to].cost = cost;
				graph[curr->to].parent = v.id;
				Q.push(curr->to);
			}
			curr = curr->next;
		}
	}
}
