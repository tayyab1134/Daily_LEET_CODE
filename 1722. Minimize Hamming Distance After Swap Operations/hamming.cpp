class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rankv[px] < rankv[py]) parent[px] = py;
        else if (rankv[px] > rankv[py]) parent[py] = px;
        else {
            parent[py] = px;
            rankv[px]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int> >& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rankv.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rankv[i] = 0;
        }

        for (int i = 0; i < allowedSwaps.size(); i++) {
            unite(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        unordered_map<int, unordered_map<int, int> > mp;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            mp[root][source[i]]++;
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (mp[root][target[i]] > 0) {
                mp[root][target[i]]--;
            } else {
                result++;
            }
        }

        return result;
    }
};