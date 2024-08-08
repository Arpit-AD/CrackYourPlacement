class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int j = 0;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[j][1]){
                j = i;
                count++;
            }
        }
        return n-count;
    }
};