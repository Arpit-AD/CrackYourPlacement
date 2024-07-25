class Solution {
    vector<string> res;
public:
    void recursion(string s, int n, int open, int close){
        if(close == n){
            res.push_back(s);
        }

        if(open < n){
            recursion(s+'(', n, open+1, close);
        }

        if(open > close){
            recursion(s+')', n, open, close+1);
        }

    }
    vector<string> generateParenthesis(int n) {
        if(n == 0) return res;

        recursion("", n, 0, 0);

        return res;
    }
};