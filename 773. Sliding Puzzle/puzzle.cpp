class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        start += to_string(board[i][j]);
    }
}

        string target = "123450";

        vector<vector<int>> neighbors = {
            {1, 3},      
            {0, 2, 4},   
            {1, 5},      
            {0, 4},      
            {1, 3, 5},   
            {2, 4}       
        };

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if (curr == target) return moves;

            int zeroPos = curr.find('0');
            for (int nextPos : neighbors[zeroPos]) {
                string next = curr;
                swap(next[zeroPos], next[nextPos]);
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }

        return -1; 
    }
};