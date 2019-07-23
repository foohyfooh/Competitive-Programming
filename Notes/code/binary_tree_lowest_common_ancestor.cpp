//Useful if repeat queries for LCA have to be made since the visited doesn't have to be reset
#include <map>

template<typename T>
Tree<T>* LCA(Tree<T>* t1, Tree<T>* t2){
  map<Tree<T>*, bool> ancestors;

  while(t1 != nullptr){
    ancestors[t1] = true;
    t1 = t1->parent;
  }

  while(t2 != nullptr){
    if(ancestors[t2]) return t2;
    t2 = t2->parent;
  }

  return nullptr;
}

//Doesn't require additional space for the map but the visited have to reset to false
template<typename T>
Tree<T>* LowestCommonAncestor(Tree<T>* t1, Tree<T>* t2){

  while(t1 != nullptr){
    t1->visited = true;
    t1 = t1->parent;
  }

  while(t2 != nullptr){
    if(t2->visited) return t2;
    t2 = t2->parent;
  }

  return nullptr;
}
