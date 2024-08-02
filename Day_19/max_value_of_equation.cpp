class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int maxVal = INT_MIN, n = points.size();
        priority_queue<pair<int, int>> pq;
        int i = 0;
        while (i < n) {
            while (!pq.empty() && abs(points[i][0] - pq.top().second) > k)
                pq.pop();

            if (!pq.empty()) {
                maxVal =
                    max(points[i][0] + points[i][1] + pq.top().first, maxVal); // xi + yi
            }

            pq.push({points[i][1] - points[i][0], points[i][0]}); // yi - xi
            i++;
        }

        return maxVal;
    }
};