// bfs.cpp
class Solution {
  const int dirx[4] = {0, 1, 0, -1};
  const int diry[4] = {1, 0, -1, 0};

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(sr, sc));
    int color = image[sr][sc];
    if (color == newColor)
      return image;
    image[sr][sc] = newColor;
    int row = image.size(), col = image[0].size();
    while (!dq.empty()) {
      auto point = dq.front();
      dq.pop_front();
      for (int i = 0; i < 4; ++i) {
        int x = point.first + dirx[i], y = point.second + diry[i];
        if (x >= 0 && x < row && y >= 0 && y < col && image[x][y] == color) {
          image[x][y] = newColor;
          dq.push_back(make_pair(x, y));
        }
      }
    }
    return image;
  }
};
