class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> stickerCounts(n, vector<int>(26, 0));
        
        for (int i = 0; i < n; ++i) {
            for (char ch : stickers[i]) {
                stickerCounts[i][ch - 'a']++;
            }
        }

        unordered_map<string, int> memo;
        memo[""] = 0;

        return dfs(stickerCounts, target, memo);
    }

private:
    int dfs(vector<vector<int>>& stickerCounts, string target, unordered_map<string, int>& memo) {
        if (memo.count(target)) return memo[target];

        vector<int> targetCount(26, 0);
        for (char ch : target) targetCount[ch - 'a']++;

        int res = INT_MAX;

        for (const auto& sticker : stickerCounts) {
            if (sticker[target[0] - 'a'] == 0) continue;

            string newTarget;
            for (int i = 0; i < 26; ++i) {
                if (targetCount[i] > 0) {
                    int remain = targetCount[i] - sticker[i];
                    for (int j = 0; j < max(0, remain); ++j) {
                        newTarget += (char)('a' + i);
                    }
                }
            }

            int tmp = dfs(stickerCounts, newTarget, memo);
            if (tmp != -1) {
                res = min(res, 1 + tmp);
            }
        }

        memo[target] = (res == INT_MAX) ? -1 : res;
        return memo[target];
    }
};