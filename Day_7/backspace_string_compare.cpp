class Solution {
public:
    string getStrFromStack(string s) {
        stack<char> st;
        string temp = "";
        for (char i : s) {
            if (i == '#') {
                if (!st.empty())
                    st.pop();
            } else
                st.push(i);
        }
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        return temp;
    }

    bool backspaceCompare(string s, string t) {
        string _s = getStrFromStack(s);
        string _t = getStrFromStack(t);

        return _s == _t;
    }
};