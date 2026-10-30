
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (grid[row][col] == '1') {
                    cnt++;

                    queue<pair<int, int>> q;
                    q.push({row, col});
                    grid[row][col] = '0';

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nr = r + dr[i];
                            int nc = c + dc[i];

                            if (nr >= 0 && nr < n &&
                                nc >= 0 && nc < m &&
                                grid[nr][nc] == '1') {

                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};
