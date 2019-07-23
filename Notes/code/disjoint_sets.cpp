#include <set>

/*
 *Add all the elements of the set s to the new set
 */
void reassign(set<int>* sets[], set<int>* s, set<int>* newSet){
	if(s == nullptr) return;
	for(auto p = s->begin(); p != s->end(); p++) sets[*p] = newSet;
	delete s;
}

#define deallocateSet(sets, s) reassign(sets, s, nullptr)

/*
 * Return true if the sets where unioned else false
 */
bool unionSets(set<int>* sets[], int x, int y){
	set<int> *xSet = sets[x], *ySet = sets[y];
	if(xSet == nullptr && ySet == nullptr){
		set<int>* s = new set<int>;
		s->insert(x);
		s->insert(y);
		sets[x] = sets[y] = s;
		return true;
	}else if(xSet == nullptr){
		ySet->insert(x);
		sets[x] = ySet;
		return true;
	}else if(ySet == nullptr){
		xSet->insert(y);
		sets[y] = xSet;
		return true;
	}else if(xSet != ySet){
		xSet->insert(ySet->begin(), ySet->end());
		reassign(sets, ySet, xSet);
		return true;
	}
	return false;
}
