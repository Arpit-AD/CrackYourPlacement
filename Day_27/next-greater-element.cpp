class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        int n = nums2.size();
        int i = n-1;
        while(i >= 0)
        {
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(st.empty())
                mp[nums2[i]] = -1;
            else 
                 mp[nums2[i]] = st.top();
            
            st.push(nums2[i]);
            i--;
        }
        
        vector<int> ansVec;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            ansVec.push_back(mp[nums1[i]]);
        }
        
        return ansVec;
        
    }
};