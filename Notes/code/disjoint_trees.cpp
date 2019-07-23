struct Tree {
	int id, rank;
	Tree* parent;
};
Tree* graph[1 .. N];

Tree* find(Tree* x){
	while(x->parent != nullptr) x  = x->parent;
	return x;
}

bool unionTrees(Tree* x, Tree* y){
	Tree *xRoot = find(x), *yRoot = find(y);

	if(xRoot == yRoot) return false;
	else if(xRoot->rank > yRoot->rank) yRoot->parent = xRoot;
	else if(yRoot->rank > xRoot->rank) xRoot->parent = yRoot;
	else {
		yRoot->parent = xRoot;
		xRoot->rank++;
	}

	return true;
}
