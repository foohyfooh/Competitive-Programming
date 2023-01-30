class Solution {
public:
    enum Direction{
      Left, Down, Right, Up
    };

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int i = 0, j = 0;
      int a = 0, b = -1, m = matrix.size(), n = matrix[0].size();
      int limit = m * n;
      vector<int> spiral;
      spiral.reserve(limit);

      Direction direction = Left;
      while(spiral.size() < limit) {
        spiral.push_back(matrix[i][j]);
        if(direction == Left) {
          j++;
          if(j == n) {
            j--;
            i++;
            n--;
            direction = Down;
          }
        } else if(direction == Down) {
          i++;
          if(i == m) {
            i--;
            j--;
            m--;
            direction = Right;
          }
        } else if(direction == Right) {
          j--;
          if(j == b) {
            j++;
            i--;
            b++;
            direction = Up;
          }
        } else if(direction == Up) {
          i--;
          if(i == a) {
            i++;
            j++;
            a++;
            direction = Left;
          }
        }
      }

      return spiral;
    }
};
