#include <iostream>
#include <cstdlib>
#include <vector>
/*
Make a graph of all of the nodes

Determine each disjoint graph in the whole graph.
Check if in each of those graphs that the sum of the amounts of the nodes for that graph is zero.
If so then it is POSSIBLE else IMPOSSIBLE

Do a depth-first traversal of the nodes in the graph to do the checking.
*/

using std::vector;

struct Node {
	int id, balance;
	bool visited;
	vector<int>* neighbours;
};

struct Graph {
	int numVertices, numEdges;
	Node* vertices;
};

Graph* buildGraph(int numVertices, int numEdges){
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	graph->vertices = (Node*) calloc(numVertices, sizeof(Node));
	graph->numVertices = numVertices;
	graph->numEdges = numEdges;
	for(int i = 0; i < numVertices; i++){
		graph->vertices[i].id = i;
		graph->vertices[i].visited = false;
		std::cin >> graph->vertices[i].balance;
		graph->vertices[i].neighbours = new vector<int>();
	}
	int from, to;
	for(int i = 0; i < numEdges; i++){
		std::cin >> from >> to;
		(*(graph->vertices[from].neighbours)).push_back(to);
		(*(graph->vertices[to].neighbours)).push_back(from);
	}
	return graph;
}

void dfTraversal(Graph* graph, int nodeId, int& sum){
	graph->vertices[nodeId].visited = true;
	sum += graph->vertices[nodeId].balance;
	vector<int> nodes = *(graph->vertices[nodeId].neighbours);
	int size = nodes.size();
	for(int i = 0; i < size; i++){
		if(!graph->vertices[nodes[i]].visited){
			dfTraversal(graph, nodes[i], sum);
		}
	}
}

int main(int argc, char** argv) {

	int testCases;
	std::cin >> testCases;
	for(;testCases > 0; testCases--){
		int numVertices, numEdges;
		std::cin >> numVertices >> numEdges;
		Graph* graph = buildGraph(numVertices, numEdges);

		int sum;
		for(int i = 0; i < numVertices; i++){
			if(!graph->vertices[i].visited){
				sum = 0;
				dfTraversal(graph, i, sum);
				if(sum != 0){
					std::cout << "IMPOSSIBLE\n";
					goto impossible;
				}
			}
		}

		std::cout << "POSSIBLE\n";
		impossible:;
	}

	return EXIT_SUCCESS;
}
