//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
      bool check(int mid, vector<int>&stalls,int k)
      {
          int i,j,temp=stalls[0],count=1;
          for(i=1;i<stalls.size();i++)
          {
              if(stalls[i]-temp>=mid)
              {
                  temp=stalls[i];
                  count++;
              }
              if(count==k)
              return true;
          }
          return false;
      }

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int si = 0, ei = stalls[n-1] - stalls[0];
        int ans = 1;
    	while(si <= ei){
    		int mid = si + (ei - si)/2;
    		if(check(mid, stalls, k)){
    		    ans = max(mid, ans);
    			si = mid + 1;
    		}
    		else {
    			ei = mid - 1;
    		}
    	}
	    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends