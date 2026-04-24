class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int u = 0;
        
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'L') {
                l++;
            } else if (moves[i] == 'R') {
                r++;
            } else {
                u++;
            }
        }
        
        int right = r + u - l;
        int left = l + u - r;
        
        if (right < 0) right = -right;
        if (left < 0) left = -left;
        
        return right > left ? right : left;
    }
};