class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> index(n);
        for (int i = 0; i < n; i++) index[i] = i;

        sort(index.begin(), index.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;

        for (int i = 0; i < n; i++) {
            int idx = index[i];

            if (directions[idx] == 'R') {
                st.push(idx);
            } else {
                while (!st.empty() && healths[idx] > 0) {
                    int top = st.top();

                    if (healths[top] < healths[idx]) {
                        st.pop();
                        healths[idx] -= 1;
                        healths[top] = 0;
                    } else if (healths[top] > healths[idx]) {
                        healths[top] -= 1;
                        healths[idx] = 0;
                    } else {
                        st.pop();
                        healths[top] = 0;
                        healths[idx] = 0;
                        break;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) result.push_back(healths[i]);
        }

        return result;
    }
};