class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {
        set<pair<int,int> > st;
        int i, j;
        for (i = 0; i < (int)obstacles.size(); i++) {
            st.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
        
        int dir = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int x = 0, y = 0;
        int maxDist = 0;
        
        for (i = 0; i < (int)commands.size(); i++) {
            if (commands[i] == -1) {
                dir = (dir + 1) % 4;
            } else if (commands[i] == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (j = 0; j < commands[i]; j++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (st.find(make_pair(nx, ny)) != st.end()) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    int dist = x * x + y * y;
                    if (dist > maxDist) {
                        maxDist = dist;
                    }
                }
            }
        }
        
        return maxDist;
    }
};