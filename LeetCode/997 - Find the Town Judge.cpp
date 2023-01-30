class Solution {
public:

  struct TrustCount {
    int numTrusted, numWhoTrust;
    TrustCount(){
      numTrusted = 0;
      numWhoTrust = 0;
    }
  };

  int findJudge(int n, vector<vector<int>>& trust) {
    vector<TrustCount> trusted(n + 1);
    for(int i = 0; i < trust.size(); i++){
      trusted[trust[i][0]].numTrusted++;
      trusted[trust[i][1]].numWhoTrust++;
    }
    for(int i = 1; i <= n; i++) {
      if(trusted[i].numTrusted == 0 && trusted[i].numWhoTrust == n - 1) {
        return i ;
      }
    }
    return -1;
  }
};
