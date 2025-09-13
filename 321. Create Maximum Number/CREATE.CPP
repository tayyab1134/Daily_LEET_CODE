class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;

        int m = nums1.size();
        int n = nums2.size();

        int start = max(0, k - n);
        int end = min(k, m);

        for (int i = start; i <= end; ++i) {
            vector<int> part1 = getMaxSubsequence(nums1, i);
            vector<int> part2 = getMaxSubsequence(nums2, k - i);
            vector<int> candidate = merge(part1, part2);
            if (greater(candidate, best)) {
                best = candidate;
            }
        }

        return best;
    }

private:
    vector<int> getMaxSubsequence(vector<int>& nums, int k) {
        vector<int> result;
        int drop = nums.size() - k;

        for (int i = 0; i < nums.size(); ++i) {
            while (!result.empty() && drop > 0 && result.back() < nums[i]) {
                result.pop_back();
                --drop;
            }
            result.push_back(nums[i]);
        }


        result.resize(k);
        return result;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;

        while (i < nums1.size() || j < nums2.size()) {
            if (compare(nums1, i, nums2, j)) {
                merged.push_back(nums1[i]);
                ++i;
            } else {
                merged.push_back(nums2[j]);
                ++j;
            }
        }

        return merged;
    }

    bool compare(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) return true;
            if (nums1[i] < nums2[j]) return false;
            ++i;
            ++j;
        }
        return (nums1.size() - i) > (nums2.size() - j);
    }

    bool greater(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size() && i < b.size(); ++i) {
            if (a[i] > b[i]) return true;
            if (a[i] < b[i]) return false;
        }
        return a.size() > b.size();
    }
};