class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return helper(s, wordSet);
    }

private:
    vector<string> helper(string s, unordered_set<string>& wordSet) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        
        }
        vector<string> result;

        if (wordSet.find(s) != wordSet.end()) {
            result.push_back(s);
        }

        for (int i = 1; i < s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.find(prefix) != wordSet.end()) {
                string suffix = s.substr(i);
                vector<string> suffixBreaks = helper(suffix, wordSet);
                for (string& str : suffixBreaks) {
                    result.push_back(prefix + " " + str);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};
