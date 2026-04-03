#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = (int)robots.size();
        vector<pair<int,int> > rb(n);
        for (int i = 0; i < n; i++) rb[i] = make_pair(robots[i], distance[i]);
        sort(rb.begin(), rb.end());
        sort(walls.begin(), walls.end());

        vector<long long> pos(n);
        vector<long long> dist(n);
        for (int i = 0; i < n; i++) {
            pos[i] = rb[i].first;
            dist[i] = rb[i].second;
        }

        int m = (int)walls.size();
        vector<long long> w(m);
        for (int i = 0; i < m; i++) w[i] = (long long)walls[i];

        vector<long long> L1(n), R1(n), L2(n), R2(n);
        for (int i = 0; i < n; i++) {
            long long leftStop = (i == 0 ? (long long)-4e18 : pos[i - 1] + 1);
            long long rightStop = (i == n - 1 ? (long long)4e18 : pos[i + 1] - 1);

            long long lL = pos[i] - dist[i];
            long long lR = pos[i];
            long long rL = pos[i];
            long long rR = pos[i] + dist[i];

            L1[i] = max(lL, leftStop);
            R1[i] = min(lR, rightStop);

            L2[i] = max(rL, leftStop);
            R2[i] = min(rR, rightStop);

            if (L1[i] > R1[i]) {
                L1[i] = 1;
                R1[i] = 0;
            }
            if (L2[i] > R2[i]) {
                L2[i] = 1;
                R2[i] = 0;
            }
        }

        vector<int> cntL(n, 0), cntR(n, 0);
        for (int i = 0; i < n; i++) {
            if (L1[i] <= R1[i]) {
                int a = (int)(lower_bound(w.begin(), w.end(), L1[i]) - w.begin());
                int b = (int)(upper_bound(w.begin(), w.end(), R1[i]) - w.begin());
                cntL[i] = b - a;
            }
            if (L2[i] <= R2[i]) {
                int a = (int)(lower_bound(w.begin(), w.end(), L2[i]) - w.begin());
                int b = (int)(upper_bound(w.begin(), w.end(), R2[i]) - w.begin());
                cntR[i] = b - a;
            }
        }

        vector<int> overlap(n - 1, 0);
        for (int i = 0; i + 1 < n; i++) {
            long long aL = L2[i];
            long long aR = R2[i];
            long long bL = L1[i + 1];
            long long bR = R1[i + 1];
            long long oL = max(aL, bL);
            long long oR = min(aR, bR);
            if (oL <= oR) {
                int x = (int)(lower_bound(w.begin(), w.end(), oL) - w.begin());
                int y = (int)(upper_bound(w.begin(), w.end(), oR) - w.begin());
                overlap[i] = y - x;
            }
        }

        const long long NEG = (long long)-4e18;
        long long dpL = cntL[0];
        long long dpR = cntR[0];

        for (int i = 1; i < n; i++) {
            long long newL = NEG;
            long long newR = NEG;

            long long cand1 = dpL + (long long)cntL[i];
            long long cand2 = dpR + (long long)cntL[i] - (long long)overlap[i - 1];
            newL = max(cand1, cand2);

            long long bestPrev = max(dpL, dpR);
            newR = bestPrev + (long long)cntR[i];

            dpL = newL;
            dpR = newR;
        }

        long long ans = max(dpL, dpR);
        return (int)ans;
    }
};