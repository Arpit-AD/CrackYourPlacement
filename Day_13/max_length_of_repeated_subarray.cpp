class Solution {
public:
    bool check(int k, vector<int>& nums1, vector<int>& nums2){
        if(k == 0)
            return k;
        int n = nums1.size();
        int m = nums2.size();
        // cout << "k" << k << "\n";
        vector<string> vecStr;
        string temp = "";
        int l = 0, r = 0;
        while(r < m)
        {
            temp += to_string(nums2[r]);
            if(r-l+1 == k)
            {
                vecStr.push_back(temp);
                int z = to_string(nums2[l]).size();
                if(z <= temp.size())
                    temp = temp.substr(z);
                l++;
            }            
            r++;     
        }
        
        // for(auto z: vecStr) cout << z << " ";
        // cout << "\n";
        
        int i = 0, j = 0; 
        string s1 = "";
        while(j < n)
        {
            s1 += to_string(nums1[j]);
            
            if(j-i+1 == k)
            {
                // cout << s1 << " ";
                if(find(vecStr.begin(),vecStr.end(), s1) != vecStr.end())
                    return true;
                int z = to_string(nums1[i]).size();
                if(z <= s1.size())
                s1 = s1.substr(z);
                i++;
            }
            j++;
            
        }
        return false;
        
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int si = 0, ei = n;
        int ans = -1;
        while(si <= ei)
        {
            int mid = ei + (si - ei)/2;
            if(check(mid, nums1, nums2))
            {
                ans = max(mid,ans);
                si = mid + 1;
            }
            else 
                ei = mid - 1;
        }
        
        return ans < 0 ? 0 : ans;
    }
};