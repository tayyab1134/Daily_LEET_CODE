class Solution {
public:
    long long maxDistance(int side, vector<vector<int> >& points, int k) {
        int n = (int)points.size();
        vector<long long> t(n);

        for (int i = 0; i < n; i++) {
            long long x = points[i][0];
            long long y = points[i][1];
            if (y == 0) t[i] = x;
            else if (x == side) t[i] = (long long)side + y;
            else if (y == side) t[i] = (long long)2 * side + ((long long)side - x);
            else t[i] = (long long)3 * side + ((long long)side - y);
        }

        sort(t.begin(), t.end());

        long long L = 0;
        long long R = 2LL * side;
        while (L < R) {
            long long mid = (L + R + 1) / 2;
            if (canChoose(t, side, k, mid)) L = mid;
            else R = mid - 1;
        }
        return L;
    }

private:
    bool canChoose(const vector<long long>& t, int side, int k, long long d) {
        int n = (int)t.size();
        long long P = 4LL * side;
        if (k <= 1) return true;

        vector<long long> tt(2 * n);
        for (int i = 0; i < n; i++) {
            tt[i] = t[i];
            tt[i + n] = t[i] + P;
        }

        vector<int> nxt(2 * n + 1);
        int j = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (j < i) j = i;
            while (j < 2 * n && tt[j] < tt[i] + d) j++;
            nxt[i] = j;
        }
        nxt[2 * n] = 2 * n;

        int maxPow = 0;
        while ((1 << maxPow) <= k) maxPow++;

        vector<vector<int> > up(maxPow, vector<int>(2 * n + 1, 2 * n));
        for (int i = 0; i <= 2 * n; i++) up[0][i] = nxt[i];
        for (int p = 1; p < maxPow; p++) {
            for (int i = 0; i <= 2 * n; i++) {
                int v = up[p - 1][i];
                up[p][i] = up[p - 1][v];
            }
        }

        for (int s = 0; s < n; s++) {
            int cur = s;
            int need = k - 1;
            for (int p = 0; p < maxPow; p++) {
                if (need & (1 << p)) cur = up[p][cur];
            }
            if (cur >= s + n) continue;

            long long span = tt[cur] - tt[s];
            if (span <= P - d) return true;
        }
        return false;
    }
};
