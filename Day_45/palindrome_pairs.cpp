
class Solution {
public:

struct trie {
    trie* next[26];
    int ind=-1;
};

    void insert(trie* root, string word, int ind) {
        trie* trav=root;
        for(int j=word.size()-1; j>=0; --j) {
            int i=word[j]-'a';
            if(!trav->next[i]) trav->next[i]=new trie();
            trav=trav->next[i];
        }
        trav->ind=ind;
    }

    bool is_palindrome(string s, int si, int ei) {
        while(si < ei && s[si]==s[ei]) {
            ++si, --ei;
        }
        return si>=ei;
    }

    vector<int> search_words(trie* root) {
        stack<trie*> dfs;
        vector<int> result;
        dfs.push(root);
        while(dfs.size()) {
            trie* trav=dfs.top(); dfs.pop();
            if(trav->ind!=-1) result.push_back(trav->ind);
            for(int i=0; i<26; ++i) {
                if(trav->next[i]) dfs.push(trav->next[i]);
            }
        }
        return result;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        trie* root = new trie();
        for (int i = 0; i < words.size(); ++i) insert(root, words[i], i);

        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            trie* trav = root;
            int j=0;
            for(; j<w.size() && trav; ++j) {
                int ind=w[j]-'a';
                //Case1 word1[0,j-1] matched reversed word[trav->ind] and word1[j, w.size()-1] is a palindrome
                if(trav->ind!=-1 && trav->ind!=i && is_palindrome(w, j, w.size()-1)) result.push_back({i, trav->ind});  
                trav=trav->next[ind];
            }
            if(!trav) continue;
            //Case 2 and Case 3: word1 matched reversed part of word2 of completely, find all words that has matched suffix and check if the prefix are a palindrome.
            for(int ind:search_words(trav))
                if(i!=ind && is_palindrome(words[ind], 0, words[ind].size()-j-1)) result.push_back({i, ind}); 
        }

        return result;
    }
};