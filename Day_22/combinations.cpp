class Solution {
    vector<vector<int>> res;
public:
    void recursion(int n, int k, int i, vector<int>& vec){
        if(k == 0){
            res.push_back(vec);
            return;
        }
        if(i > n) return;
        recursion(n, k, i+1, vec);
        vec.push_back(i);
        recursion(n, k-1, i+1, vec);
        vec.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        recursion(n, k, 1, vec);
        return res;
    }
};