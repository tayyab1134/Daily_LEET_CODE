class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > indexDiff) {
            window.erase(nums[i - indexDiff - 1]);
        }
        auto it = window.lower_bound((long long)nums[i] - (long long)valueDiff);
        if (it != window.end() && *it <= (long long)nums[i] + (long long)valueDiff) {
            return true;
        }
        window.insert(nums[i]);
    }
    
    return false;
    }
};