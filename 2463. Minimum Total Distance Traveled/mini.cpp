class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector<int> slots;
        for (int i = 0; i < factory.size(); i++) {
            int pos = factory[i][0];
            int limit = factory[i][1];
            for (int j = 0; j < limit; j++) {
                slots.push_back(pos);
            }
        }
        
        int n = robot.size();
        int m = slots.size();
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));
        
        for (int j = 0; j <= m; j++) dp[0][j] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j - 1];
                long long cost = abs((long long)robot[i - 1] - (long long)slots[j - 1]);
                if (dp[i - 1][j - 1] != (long long)1e18) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
                }
            }
        }
        
        return dp[n][m];
    }
};