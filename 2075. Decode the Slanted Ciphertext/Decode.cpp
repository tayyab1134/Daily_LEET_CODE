class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.size();
        int cols = n / rows;
        
        vector<vector<char> > grid(rows, vector<char>(cols));
        
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = encodedText[k++];
            }
        }
        
        string result = "";
        
        for (int start = 0; start < cols; start++) {
            int i = 0;
            int j = start;
            while (i < rows && j < cols) {
                result.push_back(grid[i][j]);
                i++;
                j++;
            }
        }
        
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};