class Solution {
public:
    int recursion(vector<int>& arr, int l, int r,
                  map<pair<int, int>, int>& maxi, vector<vector<int>>& dp) {
        if (l == r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = INT_MAX;
        for (int i = l; i < r; i++) {
            ans = min(ans, maxi[{l, i}] * maxi[{i + 1, r}] +
                               recursion(arr, l, i, maxi, dp) +
                               recursion(arr, i + 1, r, maxi, dp));
        }

        return dp[l][r] = ans;
    }
    
    int dpApproach(vector<int>&arr){
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recursion(arr, 0, n - 1, maxi, dp);
    }

    int mctFromLeafValues(vector<int>& arr) {
        // return dpApproach(arr);

        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : arr) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid*min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i=2 ; i<stack.size(); ++i) {
            res += stack[i]*stack[i-1];
        }
        return res;
    }
};