class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        int i, j, k;
        for (i = 0; i < (int)queries.size(); i++) {
            for (j = 0; j < (int)dictionary.size(); j++) {
                int diff = 0;
                
                for (k = 0; k < (int)queries[i].size(); k++) {
                    if (queries[i][k] != dictionary[j][k]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }
                
                if (diff <= 2) {
                    result.push_back(queries[i]);
                    break;
                }
            }
        }
        
        return result;
    }
};