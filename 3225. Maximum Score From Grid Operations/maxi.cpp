class Solution {
public:
    long long maximumScore(vector<vector<int> >& grid) {
        int n = (int)grid.size();
        if (n == 1) return 0;

        vector<vector<long long> > pref(n, vector<long long>(n + 1, 0));
        for (int col = 0; col < n; col++) {
            for (int i = 0; i < n; i++) pref[col][i + 1] = pref[col][i] + (long long)grid[i][col];
        }

        long long NEG = -(1LL << 60);

        vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, NEG));
        vector<vector<long long> > ndp(n + 1, vector<long long>(n + 1, NEG));

        for (int b = 0; b <= n; b++) dp[0][b] = 0;

        for (int j = 0; j <= n - 2; j++) {
            for (int x = 0; x <= n; x++) {
                for (int y = 0; y <= n; y++) ndp[x][y] = NEG;
            }

            for (int b = 0; b <= n; b++) {
                vector<long long> bestConstAtA(n + 1, NEG);
                vector<long long> bestAForC(n + 1, NEG);

                for (int a = 0; a <= n; a++) {
                    long long cur = dp[a][b];
                    if (cur <= NEG / 2) continue;

                    long long addConst = 0;
                    if (a > b) addConst = pref[j][a] - pref[j][b];
                    long long vConst = cur + addConst;
                    if (vConst > bestConstAtA[a]) bestConstAtA[a] = vConst;

                    long long base = cur - pref[j][b];
                    if (base > bestAForC[a]) bestAForC[a] = base;
                }

                vector<long long> bestConstForC(n + 1, NEG);
                long long run = NEG;
                for (int c = n; c >= 0; c--) {
                    if (bestConstAtA[c] > run) run = bestConstAtA[c];
                    bestConstForC[c] = run;
                }

                long long bestLess = NEG;
                for (int c = 0; c <= n; c++) {
                    if (c - 1 >= 0) {
                        long long cand = bestAForC[c - 1];
                        if (cand > bestLess) bestLess = cand;
                    }

                    long long bestVal = ndp[b][c];

                    long long v1 = bestConstForC[c];
                    if (v1 > bestVal) bestVal = v1;

                    if (bestLess > NEG / 2) {
                        long long add = 0;
                        if (c > b) add = pref[j][c] - pref[j][b];
                        long long v2 = (bestLess + pref[j][b]) + add;
                        if (v2 > bestVal) bestVal = v2;
                    }

                    ndp[b][c] = bestVal;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;
        for (int a = 0; a <= n; a++) {
            for (int b = 0; b <= n; b++) {
                long long cur = dp[a][b];
                if (cur <= NEG / 2) continue;
                int m = a;
                long long addLast = 0;
                if (m > b) addLast = pref[n - 1][m] - pref[n - 1][b];
                long long v = cur + addLast;
                if (v > ans) ans = v;
            }
        }
        return ans;
    }
};