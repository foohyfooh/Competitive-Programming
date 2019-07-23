int sets[N + 1], ranks[N + 1], sizes[N + 1];
//sets and ranks initialized to 0, size intialized to 1

int find(int x){
	return sets[x] == 0 ? x : sets[x] = find(sets[x]);
}

int size(int x){
	return sizes[find(x)];
}

bool unionSets(int x, int y){
	int xRoot = find(x), yRoot = find(y);
	if(xRoot == yRoot) return false;
	else if(ranks[xRoot] > ranks[yRoot]){
		sets[yRoot] = xRoot;
		sizes[xRoot] += sizes[yRoot];
	}else if(ranks[yRoot] > ranks[xRoot]) {
		sets[xRoot] = yRoot;
		sizes[yRoot] += sizes[xRoot];
	} else {
		sets[yRoot] = xRoot;
		ranks[xRoot]++;
		sizes[xRoot] += sizes[yRoot];
	}
	return true;
}
