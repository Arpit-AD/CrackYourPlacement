//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
struct Node{
    Node* links[26];
    bool flag ;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch){
        Node* node = new Node();
        links[ch-'a']= node;
    }
    
    Node* get(char ch)
   { return links[ch-'a'];}
    
    void setEnd()
    {flag = true;}
    
    
    bool getEnd(){
        return flag;
    }
    
};
  
class Solution{
public:
    Node*node;
    void insert(string word ,Node* root){
        Node*node = root;
        
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
                
            }
            
            node = node->get(word[i]);
        }
        
        node->setEnd();
       
    }
    
    void printAll(string str , vector<string>&temp , Node* node ){
         
        if(node->getEnd())
        temp.push_back(str);
        
       
        for(int i=0;i<26;i++){
            if(node->containsKey(i+'a')){
                
                str+=(i+'a');
                printAll(str , temp , node->get(i+'a'));
                str.pop_back();
            }
        }
       
    }
    

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>>ans;
        
       Node* root = new Node();
       for(int i=0;i<n;i++){
           insert(contact[i] , root);
       }
        
        node = root;
        string str = "";
        for(int i=0;i<s.length();i++){
       
            
            if(!node->containsKey(s[i])){
                ans.push_back({"0"});
                break;
            }
            
            else{
                vector<string>temp;
                node = node->get(s[i]);
                str+=s[i];
                printAll(str , temp ,node);
               
                ans.push_back(temp);
                
            }
        }
        
        
        while(ans.size()<s.length()){
            ans.push_back({"0"});
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends