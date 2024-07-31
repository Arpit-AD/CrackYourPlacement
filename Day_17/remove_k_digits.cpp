class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        stack<char> st;
        for (auto ch : num) {
            while (!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        while (res.size() > 0 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};