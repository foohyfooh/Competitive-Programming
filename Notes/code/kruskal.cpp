int sets[N + 1];
Edge graph[N + 1];
lld cost = 0;

sort(graph, [](Edge a, Edge b){
	return a.cost < b.cost;
};

for(int i = 1; i <= N; i++){
	bool joined = unionSets(sets, graph[i].from, graph[i].to);
	if(joined) cost += graph[i].cost;
}
