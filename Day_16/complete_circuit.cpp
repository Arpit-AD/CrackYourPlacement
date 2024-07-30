class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0, extra = 0, s = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++){
            balance += (gas[i] - cost[i]);
            if(balance < 0){
                s = i+1;
                extra += balance;
                balance = 0;
            }
        }

        return balance + extra >= 0 ? s : -1;
    }
};