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

void soln()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	int minEle = INT_MAX;
	int maxEle = INT_MIN;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> vec[i];
		maxEle = max(maxEle, vec[i]);
		minEle = min(minEle, vec[i]);
		sum += vec[i];
	}

	int lo = 0, hi = maxEle, res = -1;;
	while(hi - lo > 2){
		int mid1 = lo + (hi - lo)/3;
		int mid2 = hi - (hi - lo)/3;

		if(abs(sum - n*mid1) < abs(sum - n*mid2)){
			hi = mid2;
		}
		else {
			lo = mid1;
		}
	}

	return abs(sum - (n*(lo + hi))/2);
}

signed main()
{
   // test(t)
   soln();
   return 0;
}
