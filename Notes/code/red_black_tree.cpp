/**
Pivot the node x to a new position where a node y would be.
This makes y the root of a subtree such that y->left is now x and x->right is now y->left;
*/
template<typename T>
void rotateLeft(Tree<T>** root, Tree<T>* node){
	Tree<T>* right = node->right;

	node->right = right->left;

	if(node->right != NULL) node->right->parent = node;

	right->parent = node->parent;

	if(node->parent == NULL) (*root) = right;
	else if(node == node->parent->left) node->parent->left = right;
	else node->parent->right = right;

	right->left = node;
	node->parent = right;
}

/**
Pivot the node y to a new position where a node x would be.
This makes x the root of a subtree such that x->left is now y and y->right is now x->left
*/
template<typename T>
void rotateRight(Tree<T>** root, Tree<T>* node){
	Tree<T>* left = node->left;

	node->left = left->right;

	if(node->left != NULL) node->left->parent = node;

	left->parent = node->parent;

	if(node->parent == NULL) (*root) = left;
	else if(node == node->parent->left) node->parent->left = left;
	else node->parent->right = left;

	left->right = node;
	node->parent = left;
}

/**
Check if the tree violates any red-black tree properties
*/
template<typename T>
void handleRedBlackTreeChecks(Tree<T>** root, Tree<T>* node){
	Tree<T> *parent, *grandparent, *uncle;

	while(node != (*root) && node->colour == RED && node->parent->colour == RED) {
		parent = node->parent;
		grandparent = parent->parent;

		if(parent == grandparent->left){
			uncle = grandparent->right;

			//Case 1 - Uncle is also red
			if(uncle != NULL && uncle->colour == RED){
				grandparent->colour = RED;
				parent->colour = uncle->colour = BLACK;
				node = grandparent;
			}else{
				//Case 2 - Uncle is black and node is the right child of its parent
				if(node == parent->parent->right){
					rotateLeft(root, parent);
					node = parent;
					parent = node->parent;
				}

				//Case 3 - Uncle is black and node is the left  child of its parent
				rotateRight(root, grandparent);
				swap(parent->colour, grandparent->colour);
				node = parent;
			}
		}else{ //parent == grandparent->right
			uncle = grandparent->left;

			//Case 4 - Uncle is also red
			if(uncle != NULL && uncle->colour == RED){
				grandparent->colour = RED;
				parent->colour = uncle->colour = BLACK;
				node = grandparent;
			}else{
				//Case 5 - Uncle is black and node is the left child of its parent
				if(node == parent->left){
					rotateRight(root, parent);
					node = parent;
					parent = node->parent;
				}

				//Case 6 - Uncle is black and node is the right  child of its parent
				rotateLeft(root, grandparent);
				swap(parent->colour, grandparent->colour);
				node = parent;
			}
		}
	}

	//Case 7 - Root is not black
	(*root)->colour = BLACK;
}
