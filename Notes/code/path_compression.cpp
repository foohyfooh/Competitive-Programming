int sets[N + 1], ranks[N + 1];

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
