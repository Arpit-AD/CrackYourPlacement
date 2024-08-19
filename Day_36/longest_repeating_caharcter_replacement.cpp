class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, n = s.length();
        unordered_map<char, int> mp;
        int len = 0, maxCount = 0, ansLen = 0;

        while(j < n){
            mp[s[j]]++;
            maxCount = max(maxCount, mp[s[j]]);
            len = j-i+1;
            if(len - maxCount > k){
                mp[s[i]]--;
                i++;
            }

            ansLen = max(ansLen, j - i + 1);
            j++;
        }

        return ansLen;
    }
};