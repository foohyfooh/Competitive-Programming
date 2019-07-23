bool visited[N];

void depthFirstSearch(Vertex graph[N], int source){
	if(visited[source]) return;
	visited[soruce] = true;
	Edge* curr = graph[source].edges;
	while(curr != nullptr){
		depthFirstSearch(graph, curr->to);
		curr = curr->next;
	}
}

#include <queue>

void breadthFirstTraversal(Vertex graph[N], int source){
	queue<int> Q;
	Q.push(source);
	while(!Q.empty()){
		int pos = Q.front(); Q.pop();
		Edge* curr = graph[pos].egdes;
		while(curr != nullptr){
			if(graph[pos].colour == WHITE){
				graph[pos].colour = GREY;
				Q.push(curr->to);
			}
			curr = curr->next;
		}
		graph[pos].colour = BLACK;
	}
}
