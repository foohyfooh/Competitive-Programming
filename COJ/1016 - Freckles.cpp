/*
Kruskal's Algorithm

Read in n and the n points
Calculate the costs for each point to each other
Sort the points using priority queue
Use the sorted points to build the Minimum Cost Spanning Tree (MST)
Print the cost of the MST
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> pii;

const int MAX_POINTS = 100;
pair<double, double> points[MAX_POINTS + 1];
map<pii, double> costs;
#define x first
#define y second
auto cmp = [](pii a, pii b){
	return costs[a] > costs[b];
};
priority_queue<pii, vector<pii>, decltype(cmp)> Q(cmp);
int sets[MAX_POINTS + 1], ranks[MAX_POINTS + 1];

int find(int x){
	return sets[x] == 0 ? x : sets[x] = find(sets[x]);
}

bool unionSets(int x, int y){
	int xRoot = find(x), yRoot = find(y);

	if(xRoot == yRoot) return false;
	else if(ranks[xRoot] > ranks[yRoot]) sets[yRoot] = xRoot;
	else if(ranks[yRoot] > ranks[xRoot]) sets[xRoot] = yRoot;
	else {
		sets[yRoot] = xRoot;
		ranks[xRoot]++;
	}

	return true;
}

int main(int argc, char** argv){

	int numPoints;
	scanf("%d", &numPoints);
	for(int i = 1; i <= numPoints; i++)
		scanf("%lf%lf", &points[i].x, &points[i].y);

	pii edge;
	for(int i = 1; i < numPoints; i++){
		for(int j = i + 1; j <= numPoints; j++){
			edge = make_pair(i, j);
			costs[edge] = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
			Q.push(edge);
		}
	}

	double cost = 0;
	while(!Q.empty()){
		edge = Q.top(); Q.pop();
		if(unionSets(edge.x, edge.y)) cost += costs[edge];
	}
	printf("%.2lf", cost);

	return EXIT_SUCCESS;
}
