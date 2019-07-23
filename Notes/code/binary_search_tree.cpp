template<typename T>
Tree<T>* findOrInsert(Tree<T>** root, T data){
	if(*root == nullptr) return (*root) = new Tree<T>{data};
	Tree<T>* curr = *root;
	while(curr->data != data)
		if(data < curr->data){
			if(curr->left == nullptr) return curr->left = new Tree<T>{data, curr};
			curr = curr->left;
		}else{//data > curr->data
			if(curr->right == nullptr) return curr->right = new Tree<T>{data, curr};
			curr = curr->right;
		}
	return curr; //data exists in the Tree
}

template<typename T, typename F>
void preorder(Tree<T>* root, F visit){
  if(root == nullptr) return;
  visit(root);
  preorder(root->left);
  preorder(root->right);
}

template<typename T, typename F>
void inorder(Tree<T>* root, F visit){
  if(root == nullptr) return;
  preorder(root->left);
  visit(root);
  preorder(root->right);
}

template<typename T, typename F>
void postorder(Tree<T>* root, F visit){
  if(root == nullptr) return;
  preorder(root->left);
  preorder(root->right);
  visit(root);
}

template<typename T>
Tree<T>* lca(Tree<T>* root, Tree<T> t1, Tree<T> t2){
  if(root == nullptr) return nullptr;

  // If both t1 and t2 are smaller than root, then LCA lies in left
  if (root->data > t1->data && root->data > t2->data)
    return lca(root->left, t1, t2);

  // If both t1 and t2 are greater than root, then LCA lies in right
  if (root->data < t1->data && root->data < t2->data)
    return lca(root->right, t1, t2);

  return root;
}
