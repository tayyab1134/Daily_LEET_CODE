#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        long long total = 0;
        vector<long long> rowSum(m, 0), colSum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

       
        vector<int> vals;
        vals.reserve((size_t)m * n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                vals.push_back(grid[i][j]);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto hasValue = [&](const vector<int>& cnt, long long x) -> bool {
            if (x <= 0 || x > 100000) return false;
            auto it = lower_bound(vals.begin(), vals.end(), (int)x);
            if (it == vals.end() || *it != (int)x) return false;
            return cnt[(int)(it - vals.begin())] > 0;
        };

        auto idOf = [&](int x) -> int {
            return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
        };

        int K = (int)vals.size();
        vector<int> A(K, 0), B(K, 0); 
        if (m > 1) {
            fill(A.begin(), A.end(), 0);
            fill(B.begin(), B.end(), 0);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    B[idOf(grid[i][j])]++;

            long long sumA = 0;
            for (int cut = 0; cut < m - 1; cut++) {
            
                for (int c = 0; c < n; c++) {
                    int idx = idOf(grid[cut][c]);
                    B[idx]--;
                    A[idx]++;
                }
                sumA += rowSum[cut];
                long long sumB = total - sumA;

                if (sumA == sumB) return true;

                long long diff = llabs(sumA - sumB);
                if (sumA > sumB) {
                   
                    int rows = cut + 1, cols = n;
                    if (rows == 1) {
                   
                        if (grid[0][0] == diff || grid[0][n - 1] == diff) return true;
                    } else if (cols == 1) {
                    
                        if (grid[0][0] == diff || grid[cut][0] == diff) return true;
                    } else {
                        if (hasValue(A, diff)) return true;
                    }
                } else {
                
                    int rows = m - (cut + 1), cols = n;
                    if (rows == 1) {
                        int r = m - 1;
                        if (grid[r][0] == diff || grid[r][n - 1] == diff) return true;
                    } else if (cols == 1) {
                   
                        int r1 = cut + 1, r2 = m - 1;
                        if (grid[r1][0] == diff || grid[r2][0] == diff) return true;
                    } else {
                        if (hasValue(B, diff)) return true;
                    }
                }
            }
        }

    
        if (n > 1) {
            fill(A.begin(), A.end(), 0);
            fill(B.begin(), B.end(), 0);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    B[idOf(grid[i][j])]++;

            long long sumA = 0;
            for (int cut = 0; cut < n - 1; cut++) {
            
                for (int r = 0; r < m; r++) {
                    int idx = idOf(grid[r][cut]);
                    B[idx]--;
                    A[idx]++;
                }
                sumA += colSum[cut];
                long long sumB = total - sumA;

                if (sumA == sumB) return true;

                long long diff = llabs(sumA - sumB);
                if (sumA > sumB) {
               
                    int rows = m, cols = cut + 1;
                    if (cols == 1) {
                   
                        if (grid[0][0] == diff || grid[m - 1][0] == diff) return true;
                    } else if (rows == 1) {
                  
                        if (grid[0][0] == diff || grid[0][cut] == diff) return true;
                    } else {
                        if (hasValue(A, diff)) return true;
                    }
                } else {
              
                    int rows = m, cols = n - (cut + 1);
                    if (cols == 1) {
                        int c = n - 1;
                        if (grid[0][c] == diff || grid[m - 1][c] == diff) return true;
                    } else if (rows == 1) {

                        if (grid[0][cut + 1] == diff || grid[0][n - 1] == diff) return true;
                    } else {
                        if (hasValue(B, diff)) return true;
                    }
                }
            }
        }

        return false;
    }
};