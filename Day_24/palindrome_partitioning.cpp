class Solution {
    vector<vector<string>> res;
public:
    void recursion(string s, vector<string> &vec){
        if(s.length() == 0){
            res.push_back(vec);
            return;
        }
        string s_copy = "";
        string rev = "";

        for(int i = 0; i < s.length(); i++){
            s_copy += s[i];
            rev = s_copy;
            reverse(rev.begin(), rev.end());
            if(s_copy == rev){
                vec.push_back(s_copy);
                recursion(s.substr(i+1), vec);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        recursion(s, vec);
        return res;
    }   
};