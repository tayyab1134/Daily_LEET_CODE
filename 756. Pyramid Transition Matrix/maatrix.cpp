class Solution {
public:
    unordered_map<string, bool> memo;

    bool build(string current, unordered_map<string, vector<char> > &mp) {
        if (current.size() == 1) return true;
        if (memo.find(current) != memo.end()) return memo[current];

        vector<string> nextLevels;
        generateNext(current, 0, "", nextLevels, mp);

        for (int i = 0; i < nextLevels.size(); i++) {
            if (build(nextLevels[i], mp)) {
                memo[current] = true;
                return true;
            }
        }
        memo[current] = false;
        return false;
    }

    void generateNext(string &current, int index, string next,
                      vector<string> &res,
                      unordered_map<string, vector<char> > &mp) {
        if (index == current.size() - 1) {
            res.push_back(next);
            return;
        }
        string key = current.substr(index, 2);
        if (mp.find(key) == mp.end()) return;
        vector<char> &choices = mp[key];
        for (int i = 0; i < choices.size(); i++) {
            generateNext(current, index + 1, next + choices[i], res, mp);
        }
    }

    bool pyramidTransition(string bottom, vector<string> &allowed) {
        unordered_map<string, vector<char> > mp;
        for (int i = 0; i < allowed.size(); i++) {
            string key = allowed[i].substr(0, 2);
            mp[key].push_back(allowed[i][2]);
        }
        return build(bottom, mp);
    }
};
