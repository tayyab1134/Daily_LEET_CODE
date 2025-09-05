class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
    int n = row.size() / 2; 
    unordered_map<int, int> pos;  
    for (int i = 0; i < row.size(); i++) {
        pos[row[i]] = i;
    }

    int swaps = 0;
    for (int i = 0; i < row.size(); i += 2) {
        int first = row[i];
        int second = first ^ 1;
        if (row[i + 1] != second) {
            swaps++;
            int second_pos = pos[second];
            swap(row[i + 1], row[second_pos]);
        
            pos[row[second_pos]] = second_pos;
            pos[row[i + 1]] = i + 1;
        }
    }

    return swaps;
    }
};