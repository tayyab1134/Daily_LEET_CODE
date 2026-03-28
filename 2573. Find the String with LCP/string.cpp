class Solution {
public:
    int findp(int x, vector<int>& parent) {
        if (parent[x] != x) parent[x] = findp(parent[x], parent);
        return parent[x];
    }

    void unite(int a, int b, vector<int>& parent) {
        int pa = findp(a, parent);
        int pb = findp(b, parent);
        if (pa != pb) parent[pb] = pa;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
            }
        }

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j, parent);
                }
            }
        }

        vector<char> res(n);
        map<int, char> mp;
        char cur = 'a';

        for (int i = 0; i < n; i++) {
            int p = findp(i, parent);
            if (mp.find(p) == mp.end()) {
                if (cur > 'z') return "";
                mp[p] = cur;
                cur++;
            }
            res[i] = mp[p];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[i] == res[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }

        return string(res.begin(), res.end());
    }
};