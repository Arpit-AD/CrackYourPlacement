class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        int n = s.length();
        for(int i = 0; i < n; i++){
            string str = "";
            while(i < n && s[i] != ' '){
                str += s[i];
                i++;
            }
            if(str.length())
                vec.push_back(str);
        }

        string res = "";
        int len = vec.size();
        for(int i = len - 1; i >= 0; i--){
            res += vec[i] + " ";
        }
        res.pop_back();
        return res;
    }
};