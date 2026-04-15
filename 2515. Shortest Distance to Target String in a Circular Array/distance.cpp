class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int result = n + 1;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int clockwise = (i - startIndex + n) % n;
                int anticlockwise = (startIndex - i + n) % n;
                int dist = min(clockwise, anticlockwise);
                if (dist < result) {
                    result = dist;
                }
            }
        }

        if (result == n + 1) {
            return -1;
        }

        return result;
    }
};