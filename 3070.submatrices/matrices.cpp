class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long>> pref(m, vector<long long>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long val = grid[i][j];
                if (i > 0) val += pref[i - 1][j];
                if (j > 0) val += pref[i][j - 1];
                if (i > 0 && j > 0) val -= pref[i - 1][j - 1];
                pref[i][j] = val;
            }
        }
        
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pref[i][j] <= k) count++;
            }
        }
        
        return count;
    }
};