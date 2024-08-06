class Solution {
    vector<vector<int>> res;
public:
    void recursion(vector<int>& candidates, int target, int idx, vector<int> & z){
        if(target == 0){
            res.push_back(z);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i != idx && candidates[i] == candidates[i-1]) continue;
            
            if(candidates[i] > target) break;
            
            z.push_back(candidates[i]);
            recursion(candidates,target-candidates[i],i+1,z);
            z.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        recursion(candidates, target, 0, vec);
        return res;
    }
};