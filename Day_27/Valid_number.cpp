class Solution {
public:
    bool isNumber(string s) {
        if(s.length() == 0) return false;

        int i = -1;
        if(s[i+1] == '-' || s[i+1] == '+') i++;

        bool hasDigit = false, hasDecimal = false;
        while(1){
            if(++i == s.length()) {
                return hasDigit;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                hasDigit = true;
            }
            else if(s[i] == '.'){
                if(hasDecimal) return false;
                hasDecimal = true;
            }
            else if(s[i] == 'E' || s[i] == 'e'){
                if(!hasDigit || i+1 == s.length()) return false;
                break;
            }
            else return false;
        }

        if(s[i+1] == '-' || s[i+1] == '+') {
            if(++i == s.length()-1){
                return false;
            }
        }

        while(++i < s.length()){
            if(!(s[i] >= '0' && s[i] <= '9')) return false;
        }

        return true;
    }
};