/*
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    ____________________________________________________________
   |                                                            |
   |                   Author: Arpitad                          |
   |____________________________________________________________|
   *Pehle Brute approach soch kr dekh.. 1st and 2nd pe atleast then move aage
   *Check atleast 3-4 Test Cases
   *Use getline(cin,string_name) to get whole line as input
   *Binary search soch agar Min ya Max lena hai toh
   *Uniformity check krna hai agar nahi hai toh All possible ways try krke recursion soch
   *Agar All Possible ways me Optimization krna hai toh Use DP
   *Window ya condition di ho and contiguos elements/ string lene hote toh use Sliding Window
      terms jse - SUBARRAY/ CONTIGUOS/ SUBSTRING words present hoge
   *Jha age se kuch uthao aur peeche se kuch uthao wha prefix and suffix sum ayega
   
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


#include<bits/stdc++.h>
#include<set>
#include<math.h>

#define fast             ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ld               long double
#define all(x)           x.begin(),x.end()
#define test(t)          int t;cin>>t;while(t--)
#define ln               "\n"
#define sp               " "
#define no               cout << "NO" << ln
#define yes              cout << "YES" << ln
#define int              long long
#define precise(x,y)     fixed<<setprecision(y)<<x

using namespace std;
 
string vow = "aeiou";
 
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
 
const int dx[] = { -1 , 0 , 0 , 1 } ;
const int dy[] = { 0 , -1 , 1 , 0 } ;
 
const long double pie = 3.14159265358979 ;
const int mod = 1e9 + 7 ;

void bfs(vector<int> adjList[], int i, vector<int>& color, bool &flag){

	queue<int> pending;
	pending.push(i);
   color[i] = 1;
	while(!pending.empty()){
		int front = pending.front();
      pending.pop();
		for(auto z: adjList[front])
		{			
			if(color[z] == -1)
			{	
            pending.push(z);
            if(color[front] == 1)
               color[z] = 2;
            else color[z] = 1;
         }
         else if(color[z] == color[front]){
            flag = false;
            // return;
         }
		}
	}
}

void bfsColoring(vector<int> adjList[], int n){

   vector<int> colorBFS(n,-1);
   bool flagBFS = true;
   for(int i = 0; i < n; i++)
   {
         if(colorBFS[i] == -1)
            bfs(adjList,i, colorBFS, flagBFS);
         // if(flagBFS == false) break;
   }

   for(auto z: colorBFS) cout << z<< sp;
      cout << ln;

   if(flagBFS == true) cout << "It is a Bipartite by BFS\n";
   else cout << "It is not a Bipartite by BFS\n";

}



void dfs(vector<int> adjList[], int i , vector<int> &color, bool &flag, int clr)
{
   color[i] = clr;

   for(int z: adjList[i])
   {
      if(color[z] == -1){
         int v = (clr == 1) ? 2 : 1;
         dfs(adjList,z,color,flag,v);
      }
      else if(color[z] == clr)
      {
         flag = false;
      }
   }
}

void dfsColoring(vector<int> adjList[], int n){
   vector<int> colorDFS(n,-1);
   bool flagDFS = true;

   for(int i = 0; i < n; i++)
   {
         if(colorDFS[i] == -1)
            dfs(adjList, i, colorDFS, flagDFS,1);
   }

   for(auto z: colorDFS) cout << z<< sp;
      cout << ln;

   if(flagDFS == true) cout << "It is a Bipartite by DFS\n";
   else cout << "It is not a Bipartite by DFS\n";
}


void soln()
{
   // cout << "Hello Ad";
   int n, m;
   cin >> n >> m;
   vector<int> adjList[n];
   for(int i = 0; i < m; i++){
   	int x,y;
   	cin >> x >> y;
   	adjList[x-1].push_back(y-1);
   	adjList[y-1].push_back(x-1);
   } 

   bfsColoring(adjList,n);

   dfsColoring(adjList,n);

}

signed main()
{
   fast
   // test(t)
   soln();
   return 0;
}