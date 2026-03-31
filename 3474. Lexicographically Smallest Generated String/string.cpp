class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int len = n + m - 1;
        string res(len, '?');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] == '?' || res[i + j] == str2[j]) {
                        res[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (res[i] == '?') res[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool same = true;
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    bool changed = false;
                    for (int j = m - 1; j >= 0 && !changed; j--) {
                        int pos = i + j;
                        char original = res[pos];
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == original) continue;
                            res[pos] = c;
                            bool ok = true;
                            for (int k = max(0, pos - m + 1); k <= min(pos, n - 1); k++) {
                                if (str1[k] == 'T') {
                                    for (int t = 0; t < m; t++) {
                                        if (res[k + t] != str2[t]) {
                                            ok = false;
                                            break;
                                        }
                                    }
                                    if (!ok) break;
                                }
                            }
                            if (ok) {
                                changed = true;
                                break;
                            }
                        }
                        if (!changed) res[pos] = original;
                    }
                    if (!changed) return "";
                }
            }
        }

        return res;
    }
};