class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string str = "";
        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry)
                    str += '1';
                else
                    str += '0';
                carry = 1;
            } else if (a[i] == '0' && b[j] == '0') {
                if (carry)
                    str += '1';
                else
                    str += '0';
                carry = 0;
            } else {
                if (carry) {
                    str += '0';
                    carry = 1;
                } else {
                    str += '1';
                    carry = 0;
                }
            }
            i--, j--;
        }

        if (a.size() > b.size()) {
            while (i >= 0) {
                if (carry) {
                    if (a[i] == '1')
                        str += '0';
                    else
                        str += '1', carry = 0;
                } else {
                    str += a[i];
                }
                i--;
            }
        } else if (b.size() > a.size()) {
            while (j >= 0) {
                if (carry) {
                    if (b[j] == '1')
                        str += '0';
                    else
                        str += '1', carry = 0;
                } else {
                    str += b[j];
                }
                j--;
            }
        }
        if (carry)
            str += '1';
        reverse(str.begin(), str.end());

        return str;
    }
};