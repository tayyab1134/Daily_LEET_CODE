class Solution {
public:
    bool equal(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }

    void rotate90(vector<vector<int>>& m) {
        int n = m.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while (l < r) {
                int temp = m[i][l];
                m[i][l] = m[i][r];
                m[i][r] = temp;
                l++;
                r--;
            }
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (equal(mat, target)) return true;
            rotate90(mat);
        }
        return false;
    }
};