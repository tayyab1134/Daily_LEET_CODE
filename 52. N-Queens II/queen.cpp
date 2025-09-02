
class Solution {
public:
    int totalNQueens(int n) {
        count = 0;
        solve(0, n);
        return count;
    }

private:
    int count = 0;
    vector<int> queens; // queens[i] = column position of queen in row i

    void solve(int row, int n) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col)) {
                queens.push_back(col);
                solve(row + 1, n);
                queens.pop_back();
            }
        }
    }

    bool isValid(int row, int col) {
        for (int i = 0; i < row; i++) {
            int qCol = queens[i];
            if (qCol == col || abs(qCol - col) == abs(i - row)) {
                return false; // same column or same diagonal
            }
        }
        return true;
    }
};
