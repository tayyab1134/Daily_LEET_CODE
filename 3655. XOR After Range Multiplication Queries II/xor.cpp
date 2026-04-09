#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int> >& queries) {
        vector<int> bravexuneth = nums;

        const int MOD = 1000000007;
        int n = (int)nums.size();
        int q = (int)queries.size();
        int B = 320;

        vector< vector< vector< pair<int,int> > > > bucket(B + 1);
        int k = 1;
        while (k <= B) {
            bucket[k].clear();
            k++;
        }

        int t = 0;
        while (t < q) {
            if ((int)queries[t].size() < 4) {
                t++;
                continue;
            }
            int li = queries[t][0];
            int ri = queries[t][1];
            int ki = queries[t][2];
            int vi = queries[t][3];

            if (li < 0) li = 0;
            if (ri >= n) ri = n - 1;
            if (li > ri || ki <= 0) {
                t++;
                continue;
            }

            if (ki <= B) {
                bucket[ki].push_back(vector< pair<int,int> >());
                bucket[ki].back().push_back(pair<int,int>(li, ri));
                bucket[ki].back().push_back(pair<int,int>(vi, 0));
            } else {
                int idx = li;
                while (idx <= ri) {
                    long long val = (long long)nums[idx] * (long long)vi;
                    nums[idx] = (int)(val % MOD);
                    idx += ki;
                }
            }
            t++;
        }

        k = 1;
        while (k <= B) {
            if ((int)bucket[k].size() == 0) {
                k++;
                continue;
            }

            vector< vector<int> > diff(k);
            int r = 0;
            while (r < k) {
                int len = (n - 1 - r) / k + 1;
                diff[r].assign(len + 1, 1);
                r++;
            }

            int j = 0;
            while (j < (int)bucket[k].size()) {
                int li = bucket[k][j][0].first;
                int ri = bucket[k][j][0].second;
                int v = bucket[k][j][1].first;

                int r0 = li % k;
                int s = (li - r0) / k;
                int e = (ri - r0) / k;

                vector<int>& d = diff[r0];
                int len = (int)d.size() - 1;

                if (s < 0) s = 0;
                if (e >= len) e = len - 1;

                if (e >= s && s < len) {
                    long long x = (long long)d[s] * (long long)v;
                    d[s] = (int)(x % MOD);
                    int p = e + 1;
                    if (p <= len) {
                        long long inv = modPow((long long)v, MOD - 2, MOD);
                        long long y = (long long)d[p] * inv;
                        d[p] = (int)(y % MOD);
                    }
                }

                j++;
            }

            r = 0;
            while (r < k) {
                vector<int>& d = diff[r];
                int len = (int)d.size() - 1;
                long long cur = 1;
                int pos = 0;
                while (pos < len) {
                    cur = (cur * (long long)d[pos]) % MOD;
                    int idx = r + pos * k;
                    long long val = (long long)nums[idx] * cur;
                    nums[idx] = (int)(val % MOD);
                    pos++;
                }
                r++;
            }

            k++;
        }

        int ans = 0;
        int i = 0;
        while (i < n) {
            ans = ans ^ nums[i];
            i++;
        }
        return ans;
    }

private:
    long long modPow(long long a, long long e, long long mod) {
        long long r = 1;
        long long x = a % mod;
        long long p = e;
        while (p > 0) {
            if ((p & 1LL) != 0) r = (r * x) % mod;
            x = (x * x) % mod;
            p >>= 1LL;
        }
        return r;
    }
};