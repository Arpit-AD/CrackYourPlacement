class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        int i = 0;
        while(i < s.length()){
            if(s[i] == ']'){
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                string numStr = "";
                st.pop();
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    numStr += st.top();
                    st.pop();
                }
                reverse(numStr.begin(), numStr.end());
                int num = stoi(numStr);
                while(num--){
                    for(int i = 0; i < temp.length(); i++){
                        st.push(temp[i]);
                    }
                }
            }
            else st.push(s[i]);
            i++;
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};