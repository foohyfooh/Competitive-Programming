/*
Store original colour for image[sr][sc]
Keep track of visited
Do Breath First Search for the nodes with original colour that are connected in the 4-directions up, down, left, right
*/
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int colour) {
    int m = image.size(), n = image[0].size();
    int initialColour = image[sr][sc];
    map<pair<int, int>, bool> visited;
    queue<pair<int, int>> Q;
    Q.push(make_pair(sr, sc));
    while(!Q.empty()) {
      pair<int, int> current = Q.front(); Q.pop();
      image[current.first][current.second] = colour;
      visited[current] = true;
      if((current.first - 1) >= 0 && !visited[{current.first - 1, current.second}]
          && image[current.first - 1][current.second] == initialColour)
        Q.push({current.first - 1, current.second});
      if((current.second - 1) >= 0 && !visited[{current.first, current.second - 1}]
          && image[current.first][current.second - 1] == initialColour)
        Q.push({current.first, current.second - 1});
      if((current.first + 1) < m && !visited[{current.first + 1, current.second}]
          && image[current.first + 1][current.second] == initialColour)
        Q.push({current.first + 1, current.second});
      if((current.second + 1) < n && !visited[{current.first, current.second + 1}]
          && image[current.first][current.second + 1] == initialColour)
        Q.push({current.first, current.second + 1});
    }
    return image;
  }
};
