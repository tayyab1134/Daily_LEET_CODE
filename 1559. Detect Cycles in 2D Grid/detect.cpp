class Solution {
public:
    int m, n;
    
    bool dfs(int x, int y, int px, int py, vector<vector<char> > &grid, vector<vector<int> > &vis) {
        vis[x][y] = 1;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            
            if (!vis[nx][ny]) {
                if (dfs(nx, ny, x, y, grid, vis)) return true;
            } else if (nx != px || ny != py) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char> >& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<int> > vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, vis)) return true;
                }
            }
        }
        
        return false;
    }
};