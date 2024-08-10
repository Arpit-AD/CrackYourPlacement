//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> prvec;
	  
	    for(int i = 0; i < nums.size(); i++){
	        prvec.push_back({nums[i], i});
	    }
	    sort(prvec.begin(), prvec.end());
	    
	    int i = 0, swap = 0;
	    while(i < nums.size()){
	        if(i == prvec[i].second){
	            i++; continue;
	        }
	        swap++;
	        pair<int,int> pr = prvec[prvec[i].second];
	        prvec[prvec[i].second] = prvec[i];
	        prvec[i] = pr;
	    }
	    
	    return swap;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends