class Solution {
public:
    bool canRemove(vector<vector<int> >& grid, int r1, int r2, int c1, int c2, long long diff) {
        int i, j;
        int cnt = 0;
        int x = -1, y = -1;

        for (i = r1; i <= r2; i++) {
            for (j = c1; j <= c2; j++) {
                if (grid[i][j] == diff) {
                    cnt++;
                    x = i;
                    y = j;
                    if (cnt > 1) return true;
                }
            }
        }

        if (cnt == 0) return false;

        if (r1 == r2 && c1 == c2) return true;

        if (r1 == r2) {
            if (y == c1 || y == c2) return true;
            return false;
        }

        if (c1 == c2) {
            if (x == r1 || x == r2) return true;
            return false;
        }

        return true;
    }

    bool canPartitionGrid(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        vector<long long> row(m, 0), col(n, 0);

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        long long top = 0;
        for (i = 0; i < m - 1; i++) {
            top += row[i];
            long long bottom = total - top;

            if (top == bottom) return true;

            long long diff = llabs(top - bottom);

            if (top > bottom) {
                if (canRemove(grid, 0, i, 0, n - 1, diff)) return true;
            } else {
                if (canRemove(grid, i + 1, m - 1, 0, n - 1, diff)) return true;
            }
        }

        long long left = 0;
        for (j = 0; j < n - 1; j++) {
            left += col[j];
            long long right = total - left;

            if (left == right) return true;

            long long diff = llabs(left - right);

            if (left > right) {
                if (canRemove(grid, 0, m - 1, 0, j, diff)) return true;
            } else {
                if (canRemove(grid, 0, m - 1, j + 1, n - 1, diff)) return true;
            }
        }

        return false;
    }
};