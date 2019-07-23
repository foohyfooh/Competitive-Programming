//Useful for Disjoint Sets
struct Edge {
	int from, to, cost;
};

//Useful for Depth First Traversal and Depth First Search
struct Edge {
	int to, weight;
	Edge* next;
};
enum VertexColour {
	WHITE, GREY, BLACK
};
struct Vertex {
	int id, parent, cost;
	VertexColour colour;
	Edge* edges;
};
