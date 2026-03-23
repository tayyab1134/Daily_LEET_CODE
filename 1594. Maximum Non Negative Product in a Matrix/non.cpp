class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long dpMax[16][16];
        long long dpMin[16][16];
        int mod = 1000000007;

        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dpMax[i][0] = dpMax[i - 1][0] * grid[i][0];
            dpMin[i][0] = dpMax[i][0];
        }

        for (int j = 1; j < n; j++) {
            dpMax[0][j] = dpMax[0][j - 1] * grid[0][j];
            dpMin[0][j] = dpMax[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long a = dpMax[i - 1][j] * grid[i][j];
                long long b = dpMin[i - 1][j] * grid[i][j];
                long long c = dpMax[i][j - 1] * grid[i][j];
                long long d = dpMin[i][j - 1] * grid[i][j];

                long long mx = a;
                if (b > mx) mx = b;
                
                if (c > mx) mx = c;
                if (d > mx) mx = d;

                long long mn = a;
                if (b < mn) mn = b;
                if (c < mn) mn = c;
                if (d < mn) mn = d;

                dpMax[i][j] = mx;
                dpMin[i][j] = mn;
            }
        }

        if (dpMax[m - 1][n - 1] < 0) return -1;
        return dpMax[m - 1][n - 1] % mod;
    }
};