class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        int total = n * m;
        vector<int> arr(total);
        
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[k++] = grid[i][j] % mod;
            }
        }
        
        vector<int> prefix(total);
        
        vector<int> suffix(total);
        
        prefix[0] = 1;
        for (int i = 1; i < total; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }
        
        suffix[total - 1] = 1;
        for (int i = total - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }
        
        vector<vector<int>> result(n, vector<int>(m));
        
        k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (prefix[k] * suffix[k]) % mod;
                k++;
            }
        }
        
        return result;
    }
};