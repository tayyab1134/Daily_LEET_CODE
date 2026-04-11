class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int> > mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (unordered_map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it) {
            vector<int>& v = it->second;
            int m = v.size();
            if (m < 3) continue;
            
            for (int i = 0; i + 2 < m; i++) {
                int a = v[i];
                int b = v[i + 1];
                int c = v[i + 2];
                int dist = abs(a - b) + abs(b - c) + abs(c - a);
                if (dist < ans) ans = dist;
            }
        }
        
        if (ans == INT_MAX) return -1;
        return ans;
    }
};