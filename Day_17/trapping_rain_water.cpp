class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if(n < 3) return 0;
        
        int mx = 0, mxIdx = -1;
        for(int i = 0; i < n; i++){
            if(mx < height[i]){
                mx = height[i];
                mxIdx = i;
            }
        }
        int prevEle = 0;
        int prevIdx = -1;
        int wallSum = 0;
        int waterSum = 0;
        
        for(int i = 0; i <= mxIdx; i++)
        {
            if(height[i] >= prevEle){
                waterSum += min(height[i],prevEle) *(i-prevIdx-1);
                waterSum -= wallSum;
                wallSum = 0;
                prevEle = height[i];
                prevIdx = i;   
            }
            else{
                wallSum += height[i];
            }
        }
        
        prevEle = 0;
        prevIdx = -1;
        wallSum = 0;
        
        for(int i = n-1; i >= mxIdx; i--){
            if(height[i] >= prevEle){
                waterSum += min(height[i],prevEle) *(prevIdx-i-1);
                waterSum -= wallSum;
                wallSum = 0;
                prevEle = height[i];
                prevIdx = i;   
            }
            else{
                wallSum += height[i];
            }
        }        
        
        return waterSum;
        
    }
};