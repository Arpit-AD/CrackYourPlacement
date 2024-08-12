class Solution {
public:
    bool recursion(vector<int>& stones, int k, int idx, vector<map<int,bool>> & dp){
        if(idx == stones.size() - 1) {
            return true;
        }
        else if(idx > stones.size() - 1) {
            return false;
        }

        if(dp[idx].find(k) != dp[idx].end()) return dp[idx][k];

        dp[idx][k] = false;

        for(int i = idx + 1; i < stones.size(); i++){
            if(stones[i] - stones[idx] >= k-1 && stones[i] - stones[idx] <= k+1){
                bool canJump = recursion(stones, stones[i] - stones[idx], i, dp);
                if(canJump) {
                   dp[idx][k] = true;
                   return true;
                }
            }
            else if(stones[i] - stones[idx] > k+1) break;
        }
        return false;
    }

    bool canCross(vector<int>& stones) {
        if(stones.size() < 2) return true;
        if(stones[1] != 1) return false;
        int n = stones.size(), maxDiff = -1;

        for(int i = 1; i < n; i++){
            maxDiff = max(maxDiff, stones[i] - stones[i-1]);
        }

        vector<map<int,bool>> dp(n+1);
        return recursion(stones, 1, 1, dp);
    }
};