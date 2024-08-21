class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target) return 0;

        priority_queue<int> max_heap;
        int i = 0, n = stations.size(), stops = 0;

        int max_distance = startFuel;
        while(max_distance < target){
            while(i < n && stations[i][0] <= max_distance) {
                max_heap.push(stations[i][1]);
                i++;
            }

            if(max_heap.empty()) return -1;

            max_distance += max_heap.top();
            max_heap.pop();
            stops++;
        }
        
        return stops;
    }
};