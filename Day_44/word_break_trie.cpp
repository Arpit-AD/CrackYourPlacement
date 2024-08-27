//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(const string& word, int start, int end) {
        TrieNode* node = root;
        for (int i = start; i < end; i++) {
            int index = word[i] - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool wordBreakHelper(const string& s, int start) {
        if (start == s.size()) {
            return true;
        }
        for (int end = start + 1; end <= s.size(); end++) {
            if (search(s, start, end) && wordBreakHelper(s, end)) {
                return true;
            }
        }
        return false;
    }
};

class Solution{
    public:    
    int wordBreak(string A, vector<string> &B) {
        Trie trie;
        for (const string& word : B) {
            trie.insert(word);
        }

        return trie.wordBreakHelper(A, 0) ? 1 : 0;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends