class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int shift = k % n;
        
        for (int i = 0; i < m; i++) {
            vector<int> temp(n);
            
            if (i % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    temp[j] = mat[i][(j + shift) % n];
                }
            } else {
                for (int j = 0; j < n; j++) {
                    temp[j] = mat[i][(j - shift % n + n) % n];
                }
            }
            
            for (int j = 0; j < n; j++) {
                if (temp[j] != mat[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};