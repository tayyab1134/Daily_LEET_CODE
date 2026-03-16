class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> s;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s.insert(grid[i][j]);
                
                for (int k = 1; ; k++) {
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n) break;
                    
                    int sum = 0;
                    int x = i - k;
                    int y = j;
                    
                    int t;
                    
                    for (t = 0; t < k; t++) {
                        sum += grid[x + t][y + t];
                    }
                    
                    for (t = 0; t < k; t++) {
                        sum += grid[x + k + t][y + k - t];
                    }
                    
                    for (t = 0; t < k; t++) {
                        sum += grid[x + 2 * k - t][y - t];
                    }
                    
                    for (t = 0; t < k; t++) {
                        sum += grid[x + k - t][y - k + t];
                    }
                    
                    s.insert(sum);
                }
            }
        }
        
        vector<int> res;
        set<int>::reverse_iterator it = s.rbegin();
        
        int count = 0;
        while (it != s.rend() && count < 3) {
            res.push_back(*it);
            ++it;
            count++;
        }
        
        return res;
    }
};