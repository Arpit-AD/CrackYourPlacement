class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        char alphabets[26];
        for (int i = 0; i < 26; i++) {
            alphabets[i] = 'a' + i;
        }
        queue<string> que;
        unordered_map<string, int> countMap;
        unordered_map<string, bool> presentMap;

        for (auto z : wordList)
            presentMap[z] = true;

        que.push(beginWord);
        countMap[beginWord] = 1;

        while (!que.empty()) {
            string word = que.front();

            for (int i = 0; i < word.length(); i++) {
                string _word = word;
                for (int j = 0; j < 26; j++) {
                    _word[i] = alphabets[j];
                    if (presentMap[_word] && !countMap[_word]) {
                        que.push(_word);
                        countMap[_word] = countMap[word] + 1;
                    }
                }
            }
            que.pop();
        }

        return countMap[endWord];
    }
};