class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int> >& queries) {
        long long mod = 1000000007;
        int i;
        int n = nums.size();
        int q = queries.size();

        for (i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;
            while (idx <= r) {
                nums[idx] = (long long)nums[idx] * v % mod;
                idx += k;
            }
        }

        int result = 0;
        for (i = 0; i < n; i++) {
            result ^= nums[i];
        }

        return result;
    }
};