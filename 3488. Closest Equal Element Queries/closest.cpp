class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int> > mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans(queries.size());
        
        for (int i = 0; i < (int)queries.size(); i++) {
            int idx = queries[i];
            int val = nums[idx];
            vector<int>& v = mp[val];
            
            if (v.size() == 1) {
                ans[i] = -1;
                continue;
            }
            
            int pos = lower_bound(v.begin(), v.end(), idx) - v.begin();
            
            int leftIndex, rightIndex;
            
            if (pos == 0) {
                leftIndex = v[v.size() - 1];
            } else {
                leftIndex = v[pos - 1];
            }
            
            if (pos == (int)v.size() - 1) {
                rightIndex = v[0];
            } else {
                rightIndex = v[pos + 1];
            }
            
            int distLeft = abs(idx - leftIndex);
            distLeft = min(distLeft, n - distLeft);
            
            int distRight = abs(idx - rightIndex);
            distRight = min(distRight, n - distRight);
            
            ans[i] = min(distLeft, distRight);
        }
        
        return ans;
    }
};