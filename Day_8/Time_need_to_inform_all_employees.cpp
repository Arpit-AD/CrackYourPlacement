class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        int max_time = 0;
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        queue<pair<int, int>> que;
        que.push({headID, 0}); 

        while(!que.empty()) {
            pair<int, int> temp = que.front();
            int curr_emp  = temp.first;
            int curr_time = temp.second;
            
            max_time = max(max_time, curr_time);
            
            que.pop();
            
            for(int &v : adj[curr_emp]) {
                que.push({v, curr_time + informTime[curr_emp]}); //Time at which v recieves the information
            }
            
        }

        return max_time;
    }
};