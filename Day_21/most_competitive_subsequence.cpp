class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;

        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && st.top() > nums[i]  && nums.size() - i > k - st.size()) st.pop();
            if(st.size() < k)
                st.push(nums[i]);
        }

        vector<int> res(k);
        for(int i = k-1; i>= 0; i--){
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};