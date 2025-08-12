class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size(), n = image[0].size();

        int oldcolor = image[sr][sc];
  if (oldcolor == color) return image; 

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
            int indX = q.front().first, indY = q.front().second;
            q.pop();
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {-1, 1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int x = indX + dx[i];
                int y = indY + dy[i];

                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                if (image[x][y] == oldcolor) {
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }
        return image;
    }
};