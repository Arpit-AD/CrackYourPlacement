class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> front(n, 0);
        front[0] = cardPoints[0];
        vector<int> back(n, 0);
        back[0] = cardPoints[n - 1];
        for (int i = 1; i < n; i++)
            front[i] = front[i - 1] + cardPoints[i];
        for (int i = 1; i < n; i++)
            back[i] = back[i - 1] + cardPoints[n - 1 - i];

        if (k == n)
            return front[n - 1];
        int maxRes = -1e9;
        for (int i = 0; i < n; i++) {
            if (k - i - 2 >= 0) {
                int frontRes = back[i] + front[k - i - 2];
                int backRes = front[i] + back[k - i - 2];

                maxRes = max({frontRes, backRes, maxRes});
            }
        }

        maxRes = max({back[k - 1], front[k - 1], maxRes});

        return maxRes;
    }
};