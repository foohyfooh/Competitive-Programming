class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    // bool isEven = matrix.size() % 2 == 0;
    for(int i = 0, n = matrix.size(), middle = n / 2; i < middle; i++) {
      // cout << "(i, n) = " << i << " " << n << "\n";
      // cout << "-----\n";
      for(int j = 0, m = n - i - 1; (i + j) < m; j++) {
        // cout << "(j, m) = " << j <<  " " << m << "\n";
        // cout << i << " " << (i + j) << "\n";
        // cout << (m - j) << " " << i << "\n";
        // cout << m << " " << (m - j) << "\n";
        // cout << (i + j) << " " << m << "\n";
        // cout << "--\n";
        int temp = matrix[i][i + j];
        matrix[i][i + j] = matrix[m - j][i];
        matrix[m - j][i] = matrix[m][m - j];
        matrix[m][m - j] = matrix[i + j][m];
        matrix[i + j][m] = temp;
      }
      // cout << "----------------\n";
    }
  }
};
