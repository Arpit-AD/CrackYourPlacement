class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && st.top().first == s[i]){
                if(st.top().second + 1 == k){
                    st.pop();
                }
                else{
                    st.top().second += 1;
                }
            }
            else{
                st.push({s[i], 1});
            }
        }
        string res = "";
        while(!st.empty()){
            int num = st.top().second;
            char a = st.top().first;
            while(num--){
                res += a;
            }
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};