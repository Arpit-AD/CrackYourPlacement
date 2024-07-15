class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minElement = prices[0];
        int _maxProfit = 0;
        for(int i = 1; i < (int)prices.size(); i++){
            _maxProfit = max(_maxProfit, prices[i] - minElement);
            minElement = min(minElement, prices[i]);
        }

        return _maxProfit;
    }
};