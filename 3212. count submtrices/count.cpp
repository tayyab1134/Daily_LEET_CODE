class Solution {
public:
    int numberOfSubmatrices(vector<vector<char> >& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> > px(n + 1, vector<int>(m + 1, 0));
        vector<vector<int> > py(n + 1, vector<int>(m + 1, 0));
        
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                px[i + 1][j + 1] = px[i][j + 1] + px[i + 1][j] - px[i][j] + (grid[i][j] == 'X');
                py[i + 1][j + 1] = py[i][j + 1] + py[i + 1][j] - py[i][j] + (grid[i][j] == 'Y');
            }
        }
        
        int result = 0;
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                int x = px[i + 1][j + 1];
                int y = py[i + 1][j + 1];
                if (x > 0 && x == y) result++;
            }
        }
        
        return result;
    }
};