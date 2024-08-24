class Solution {
public:
    int areaInHistogram(vector<int>& heights) {
        int n = heights.size();
        // LEFT NSE
        vector<int> left(n);
        stack<int> st1;
        int i = 0;
        while (i < n) {
            while (!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();

            left[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
            i++;
        }

        // RIGHT NSE

        vector<int> right(n);
        stack<int> st2;
        i = n - 1;
        while (i >= 0) {
            while (!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();

            right[i] = st2.empty() ? n : st2.top();
            st2.push(i);
            i--;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat[0].size();
        vector<int> vec(m);
        int largestAr = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == '0')
                    vec[j] = mat[i][j] - '0';
                else
                    vec[j] += mat[i][j] - '0';
            }
            largestAr = max(largestAr, areaInHistogram(vec));
        }

        return largestAr;
    }
};