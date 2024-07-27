class Solution {
    int dp[601][101][101];
public:
    pair<int, int> getZero_OneCount(string str) {
        int cnt_0 = 0, cnt_1 = 0;
        for (char c : str) {
            if (c == '0')
                cnt_0++;
            else
                cnt_1++;
        }
        pair<int, int> pr = {cnt_0, cnt_1};

        return pr;
    }

    int recursion(vector<string>& strs, int zero, int one, int m,
                  int n, int i) {

        if (m < zero || n < one) {
            return 0;
        }

        if (i > strs.size() - 1)
            return 0;
        if(dp[i][zero][one] != -1) return dp[i][zero][one];

        int ans1 = 0, ans2 = 0, ans3 = 0;
        pair<int,int> pr = getZero_OneCount(strs[i]);
        if (zero + pr.first <= m && one + pr.second <=  n) {
            ans1 = 1 + recursion(strs, zero + pr.first,
                                 one + pr.second, m, n, i + 1);
            ans2 = recursion(strs, zero, one, m, n, i + 1);
        } else
            ans3 = recursion(strs, zero, one, m, n, i + 1);

        return dp[i][zero][one] = max({ans1, ans2, ans3});
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        int maxLen = recursion(strs, 0, 0, m, n, 0);

        return maxLen;
    }
};