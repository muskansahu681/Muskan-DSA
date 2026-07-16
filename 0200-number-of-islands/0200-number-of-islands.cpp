class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        int count = 0;

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1' && vis[i][j] == 0) {

                    count++;
                    vis[i][j] = 1;
                    q.push({i, j});

                    while (!q.empty()) {

                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {

                            int newRow = x + row[k];
                            int newCol = y + col[k];

                            if (newRow >= 0 && newRow < m &&
                                newCol >= 0 && newCol < n &&
                                grid[newRow][newCol] == '1' &&
                                vis[newRow][newCol] == 0) {

                                vis[newRow][newCol] = 1;
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};