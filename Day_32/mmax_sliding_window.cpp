class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        int i = 0, j = 0;
        vector<int> vec;
        while(j < nums.size())
        {
            ms.insert(nums[j]);
            if(j-i+1 == k)
            {
                vec.push_back(*ms.rbegin());
                auto it = ms.find(nums[i]);
                ms.erase(it);
                i++;
            }
            j++;
        }
        return vec;
    }
};