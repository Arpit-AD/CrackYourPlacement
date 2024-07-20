//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int i, int j, int n, vector<vector<int>> & visited){
        if(i < 0 || j < 0 || i >= n || j >= n) return false;
        if(visited[i][j]) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int a[] = {1,1,-1,-1,2,2,-2,-2};
	    int b[] = {2,-2,2,-2,1,-1,1,-1};
	    vector<vector<int>> visited(N, vector<int>(N, 0));
	    int min_moves = 1e9;
	    queue<pair<int,pair<int,int>>> pq;
	    pq.push({0,{KnightPos[0]-1, KnightPos[1]-1}});
	    
	    while(!pq.empty()){
	        pair<int,pair<int,int>> pr = pq.front();
	        int dist = pr.first;
	        pair<int,int> vertices = pr.second;
	        int i = vertices.first, j = vertices.second;
	         pq.pop();
	        for(int idx = 0; idx < 8; idx++){
	            int temp_i = i + a[idx], temp_j = j + b[idx];
	            if(isValid(temp_i, temp_j, N, visited)){
	                visited[temp_i][temp_j] = 1;
	                if(temp_i == TargetPos[0]-1 && temp_j == TargetPos[1]-1)
	                    min_moves = min(min_moves, dist + 1);
	                pq.push({dist+1, {temp_i, temp_j}});
	            }
	        }
	       
	    }
	    
	    return min_moves == 1e9? 0 : min_moves;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends