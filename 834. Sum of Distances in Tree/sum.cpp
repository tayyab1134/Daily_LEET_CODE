class Solution {
public:
    vector<int> res, count;
    vector<vector<int>> tree;
    void postOrder(int node, int parent) {
        for (int i = 0; i < tree[node].size(); ++i) {
            int child = tree[node][i];
            if (child == parent) continue;
            postOrder(child, node);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }


    void preOrder(int node, int parent, int n) {
        for (int i = 0; i < tree[node].size(); ++i) {
            int child = tree[node][i];
            if (child == parent) continue;
            res[child] = res[node] - count[child] + (n - count[child]);
            preOrder(child, node, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.resize(n, 0);
        count.resize(n, 1); 

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        postOrder(0, -1);
        preOrder(0, -1, n);

        return res;
    }
};
