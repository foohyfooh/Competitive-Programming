/*
Get the points that are zeros then update rows and colums for those points
*/
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    std::vector<pair<int, int>> points;

    for(int i = 0; i < matrix.size(); i++) {
      for(int j = 0; j < matrix[i].size(); j++) {
        if(matrix[i][j] == 0) {
          points.push_back(make_pair(i, j));
        }
      }
    }

    for(pair<int, int> p: points) {
      for(int i = 0; i < matrix[p.first].size(); i++) {
        matrix[p.first][i] = 0;
      }
      for(int j = 0; j < matrix.size(); j++) {
        matrix[j][p.second] = 0;
      }
    }
  }
};
