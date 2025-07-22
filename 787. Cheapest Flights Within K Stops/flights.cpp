class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0], v = flights[i][1], price = flights[i][2];
            graph[u].push_back({v, price});
        }

        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, src, 0});

        
        vector<int> dist(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        dist[src] = 0;
        stops[src] = 0;

        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            
            int cost = top[0];
            int city = top[1];
            int stop = top[2];

            if (city == dst) return cost;

            if (stop > k) continue;

            for (int j = 0; j < graph[city].size(); j++) {
                int nei = graph[city][j].first;
                int price = graph[city][j].second;
                int newCost = cost + price;

                if (newCost < dist[nei] || stop + 1 < stops[nei]) {
                    dist[nei] = newCost;
                    stops[nei] = stop + 1;
                    pq.push({newCost, nei, stop + 1});
                }
            }
        }

        return -1;
    }
};
