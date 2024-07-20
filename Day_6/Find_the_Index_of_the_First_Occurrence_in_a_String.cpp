class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        int i = 0, j = 0;
        string s = "";
        bool flag = false;
        while(j < haystack.size())
        {
            s += haystack[j];
            if(j - i + 1 < len)
            {
                j++;
            }
            else if(j- i + 1 == len)
            {
                if(s == needle) flag = true;
                if(flag) break;
                s = s.substr(1);
                i++;
                j++;
            }        
        }
        
        if(flag) return i;
        
        return -1;
    }
};