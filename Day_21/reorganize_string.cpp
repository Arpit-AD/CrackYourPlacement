class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++) freq[s[i] - 'a']++;

        int max = 0, letter = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > max){
                max = freq[i];
                letter = i;
            }
        }
        
        if(max > (s.length() + 1)/2) return "";

        vector<char> res(s.length());
        int index = 0;

        while(freq[letter]--){
            res[index] = letter + 'a';
            index += 2;
        }

        for(int i = 0; i < 26; i++){

            while(freq[i]-- > 0){
                if(index >= res.size()) index = 1;
                res[index] = i + 'a';
                index += 2;
            }
        }


        return string(res.begin(), res.end());
    }
};