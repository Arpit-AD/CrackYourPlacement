class Solution {
public:
    string solve(int num) {
        vector<string> units = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};  
        vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string res = "";

        if(num / 100 > 0){
            res += units[num/100 - 1] + " Hundred";
            num %= 100;

            if(num > 0) res += " ";
        }        

        if(num > 0 && num < 20){
            res += units[num - 1];
        }
        else if (num >= 20){
            res += tens[num/10 - 2];
            if(num % 10 > 0){
                res += " " + units[num % 10 - 1];
            }
        }

        return res;
    }
    string numberToWords(int _num) {
        if(_num == 0) return "Zero"; // only and one edge case.

        vector<string> thousandth = {"Thousand", "Million", "Billion"};
        int idx = -1, num = _num;
        string res = "";
        // group 3 terms

        while(num > 0){
            string curr = solve(num % 1000);
            
            if(curr.length() > 0){
                if(res.length() > 0){
                    res = curr + " " + (idx > -1 ? thousandth[idx] + " " : "") + res;
                }
                else{
                    res = curr + (idx > -1 ? " " + thousandth[idx] : "");
                }
            }
            idx++;
            num = num /1000;
        }


        return res;
    }
};