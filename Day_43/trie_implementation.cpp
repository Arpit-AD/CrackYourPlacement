// implementation of Trie

class TrieNode {
public:
    bool isEndPoint;
    TrieNode* dic[26];
    TrieNode(bool isEndPoint = false): isEndPoint(isEndPoint) {
        for(int i = 0; i < 26; i++)
            dic[i] = nullptr;
    }
};

class WordDictionary {
public:
    TrieNode* Trie;
    WordDictionary() {
        Trie =  new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = Trie;
        for(int i : word) {
            if(cur->dic[i-'a'] == nullptr)
                cur->dic[i-'a'] = new TrieNode();
            cur = cur->dic[i-'a'];
        }
        cur->isEndPoint = true;
    }

    bool search(string word) {
        return searchDot(word, Trie, 0);
    }
    
    bool searchDot(string& word, TrieNode* cur, int idx = 0) {
        for(int i = idx; i < word.size(); i++) {
            if(word[i] == '.') {
                for(int j = 0; j < 26; j++)
                    if(cur->dic[j] && searchDot(word, cur->dic[j], i+1)) 
                        return true;
                return false;
            }
            if(cur->dic[word[i]-'a'] == nullptr)
                return false;
            cur = cur->dic[word[i]-'a'];
            //cout << word;
        }
        return cur->isEndPoint;
    }
} ;


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */