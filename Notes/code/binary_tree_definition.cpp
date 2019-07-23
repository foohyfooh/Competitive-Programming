enum TreeColour{
	RED, BLACK
};

template<typename T>
struct Tree{
	T data;
	Tree<T> *parent, *left, *right;
	TreeColour colour;
	bool visited;
};
