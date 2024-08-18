
class SegmentTree{
    vector<int> vec;
    vector<int> seg;
public:
    SegmentTree(){}

    void modifyArr(vector<int>& nums){
        vec = nums;
        int n = nums.size();
        seg.resize(4*n);
        build(0, 0, n-1);
    }

    void build(int node, int low, int high){
        if(low == high) {
            seg[node] = vec[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*node+1, low, mid);
        build(2*node+2, mid + 1, high);

        seg[node] = seg[2*node + 1] + seg[2*node + 2];
    }
    
    int query(int node, int low, int high, int L, int R){
        if(high < L || R < low) return 0;

        if(high <= R && low >= L) return seg[node];

        int mid = (low + high)/2;

        int left = query(node*2+1, low, mid, L, R);
        int right = query(node*2+2, mid+1, high, L, R);

        return left + right;
    }

    int hitQuery(int left, int right){
        int n = vec.size();
        return query(0, 0, n-1, left, right);
    }
};

class NumArray {
    SegmentTree sgTree;
public:
    NumArray(vector<int>& nums) {
        sgTree.modifyArr(nums);
    }
    
    int sumRange(int left, int right) {
        return sgTree.hitQuery(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */