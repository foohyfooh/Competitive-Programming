int lca(int u, int v){
	int uEncounter = firstEncouner[u], vEncounter = firstEncouner[v];
	if(uEncounter > vEncounter) return newIndexToOldIndex[query(vEncounter, uEncounter)];
	return newIndexToOldIndex[query(uEncounter, vEncounter)];
}
