//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    
    bool recursion(int a[], int n, int k, int i, int sum, int target, int ele){
        if(ele == n && k == 0) return true;
        
        bool possible = false;
        for(int it = 0; it < n; it++){
            if(a[it] != 0){            
                int temp = a[it];
                a[it] = 0;
                if(sum + temp < target){
                    possible |= recursion(a, n, k, it, sum + temp, target, ele + 1);
                }
                else if(sum + temp == target){
                    possible |= recursion(a, n, k-1, it, 0, target, ele + 1);
                }
                a[it] = temp;
            }
        }
        
        return possible;
    }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
        int sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
         
        if(sum % k) return false;
        
        int target = sum/k;
        int ele = 0;
        return recursion(a, n, k, 0, 0, target, ele);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends