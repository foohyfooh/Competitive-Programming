/*
Read in the graph
Perform Dijkstra's Algorithm
Print the distance of the home vertex
*/
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;

typedef long long int lld;
const int MAX_PLACES = 100;
constexpr lld INF = LONG_LONG_MAX / 2;

struct Edge {
	int to;
	lld weight;
	Edge* next;
};
struct Vertex {
	lld cost;
	Edge* edges;
	Vertex(){
		edges = nullptr;
		cost = INF;
	}
};

int cost[MAX_PLACES + 1][MAX_PLACES + 1];
Vertex graph[MAX_PLACES + 1];
auto cmp = [](int u, int v) {
	return graph[u].cost > graph[v].cost;
};
priority_queue<int, vector<int>, decltype(cmp)> Q(cmp);

int main(int argc, char** argv){

	int numInterests, numTeleports;
	lld dist;

	scanf("%d%d", &numInterests, &numTeleports);
	for(int i = 2; i <= numInterests; i++){
		scanf("%lld", &dist);
		Edge* e = new Edge{i, dist};
		e->next = graph[i - 1].edges;
		graph[i - 1].edges = e;
	}

	int from, to;
	for(int i = 1; i <= numTeleports; i++){
		scanf("%d%d", &from, &to);
		Edge* e = new Edge{to, 1};
		e->next = graph[from].edges;
		graph[from].edges = e;
	}

	graph[1].cost = 0;
	Q.push(1);

	while(!Q.empty()){
		int pos = Q.top(); Q.pop();
		if(pos == numInterests) break;
		Vertex v = graph[pos];
		Edge* curr = v.edges;

		while(curr != nullptr){
			if((v.cost + curr->weight) < graph[curr->to].cost){
				graph[curr->to].cost = v.cost + curr->weight;
				Q.push(curr->to);
			}
			curr = curr->next;
		}
	}

	printf("%lld", graph[numInterests].cost);

	return EXIT_SUCCESS;
}
