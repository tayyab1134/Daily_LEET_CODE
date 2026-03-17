class Solution {
public:
    int largestSubmatrix(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int> > height(m, vector<int>(n, 0));
        
        for (int j = 0; j < n; j++) {
            height[0][j] = matrix[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    height[i][j] = 0;
                } else {
                    height[i][j] = height[i - 1][j] + 1;
                }
            }
        }
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            vector<int> temp = height[i];
            sort(temp.begin(), temp.end(), greater<int>());
            
            for (int j = 0; j < n; j++) {
                int area = temp[j] * (j + 1);
                if (area > result) {
                    result = area;
                }
            }
        }
        
        return result;
    }
};