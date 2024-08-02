class Solution {
public:
    int minDeletions(string s) {
        map<int,int> mp;
        vector<int> charArr(26, 0);
        int n = s.length();
        for(int i = 0; i < n; i++){
            charArr[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(charArr[i]){
                mp[charArr[i]]++;
            }
        }
        auto it = mp.begin();
        int resCnt = 0;
        while(it != mp.end()){
            int ele = it->first, count = it->second, initial_ele = it->first;
            while(count > 1){
                while(mp.find(ele) != mp.end() && ele > 0){
                    ele--;
                }
                if(ele == 0) resCnt += initial_ele;
                else {
                    mp[ele] = 1;
                    resCnt +=  initial_ele - ele;
                }

                count--;
            }
            it++;
        }
        return resCnt;
    }
};