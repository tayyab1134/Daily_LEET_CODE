class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        int result = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int length = dfs(matrix, i, j, memo);
                result = max(result, length);
            }
        }

        return result;
    }

private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int dfs(vector<vector<int>>& matrix, int i, int j,
            vector<vector<int>>& memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int maxLength = 1;

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() &&
                matrix[x][y] > matrix[i][j]) {
                int path = 1 + dfs(matrix, x, y, memo);
                maxLength = max(maxLength, path);
            }
        }

        memo[i][j] = maxLength;
        return maxLength;
    }
};
