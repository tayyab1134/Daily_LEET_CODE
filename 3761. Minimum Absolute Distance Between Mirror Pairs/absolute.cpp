class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (mp.find(nums[j]) != mp.end()) {
                ans = min(ans, j - mp[nums[j]]);
            }
            int rev = reverseNum(nums[j]);
            mp[rev] = j;
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};