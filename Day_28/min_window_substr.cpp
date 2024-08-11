class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();

        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++) {
            mp[t[i]]++;
        }

        int i = 0, j = 0, charLen = m, minLen = INT_MAX, s_idx = -1;
        while (j < n) {
            mp[s[j]]--;
            if (mp[s[j]] >= 0) {
                charLen--;
            }

            while (charLen == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    s_idx = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    charLen++;
                i++;
            }
            j++;
        }

        return s_idx == -1 ? "" : s.substr(s_idx, minLen);
    }
};