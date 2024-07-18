class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int leftIdx = 0, rightIdx = n-1; 
        int _maxArea = 0;
        while(leftIdx < rightIdx){
            int currentArea = min(height[leftIdx], height[rightIdx])*(rightIdx - leftIdx);
            _maxArea = max(currentArea, _maxArea);
            if(height[leftIdx] < height[rightIdx]) leftIdx++;
            else rightIdx--;
        }

        return _maxArea;
    }
};