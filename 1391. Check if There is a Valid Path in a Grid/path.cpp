class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > vis(m, vector<int>(n, 0));
        
        vector<vector<vector<int> > > dirs(7);
        
        dirs[1] = {{0,-1},{0,1}};
        dirs[2] = {{-1,0},{1,0}};
        dirs[3] = {{0,-1},{1,0}};
        dirs[4] = {{0,1},{1,0}};
        dirs[5] = {{0,-1},{-1,0}};
        dirs[6] = {{0,1},{-1,0}};
        
        queue<pair<int,int> > q;
        q.push(make_pair(0,0));
        vis[0][0] = 1;
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;
            
            if(x == m - 1 && y == n - 1) return true;
            
            int type = grid[x][y];
            
            for(int i = 0; i < dirs[type].size(); i++) {
                int nx = x + dirs[type][i][0];
                int ny = y + dirs[type][i][1];
                
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(vis[nx][ny]) continue;
                
                int nextType = grid[nx][ny];
                
                for(int j = 0; j < dirs[nextType].size(); j++) {
                    if(nx + dirs[nextType][j][0] == x && ny + dirs[nextType][j][1] == y) {
                        vis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                        break;
                    }
                }
            }
        }
        
        return false;
    }
};