class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> nextGreater(n , 0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temp[st.top()] <= temp[i]) st.pop();
            if(!st.empty())
                nextGreater[i] = abs(i-st.top());
            st.push(i);
        }

        return nextGreater;
    }
};