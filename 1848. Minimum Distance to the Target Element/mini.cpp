class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = 1000000;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                int d = i - start;
                if (d < 0) d = -d;
                if (d < ans) ans = d;
            }
        }
        return ans;
    }
};