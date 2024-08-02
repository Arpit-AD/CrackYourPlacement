class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.length(), i = 0;

        while (i < n) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            string temp = "";
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(temp);
            }
        }

        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        if (res.length() == 0)
            return "/";

        return res;
    }
};