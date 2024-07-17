#include <bits/stdc++.h>
using namespace std;

vector<char> printDups(string str)
{
    unordered_map<char, int> countMap;
    vector<char> charArr;
    for (int i = 0; i < str.length(); i++) {
        countMap[str[i]]++;
    }
    for (auto it : countMap) {
        if (it.second > 1)
            charArr.push_back(it.first);
    }
}
/* Driver code*/
int main()
{
    string str;
    cin >> str;
    vector<char> vec = printDups(str);
    for(auto it: vec) cout << it << " ";
    return 0;
}
