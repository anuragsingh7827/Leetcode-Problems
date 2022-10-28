//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class node{
public:
    char ch;
    bool isTerminal;
    map<char,node*> h;
    node(char ch){
        this -> ch = ch;
        isTerminal = false;
    }
};
class trie{
public:
    node* root = new node('\0');
    void insert(string word){
        int n = word.length();
        node* temp = root;
        for(int i= 0; i < n ; i++){
            char ch = word[i];
            if(temp -> h.count(ch)) temp = temp -> h[ch];
            else{
                temp -> h[ch] = new node(ch);
                temp = temp -> h[ch];
            } 
        }
        temp -> isTerminal = true;
    }
};
class Solution{
public:
    void helper(node* temp, trie t, vector<string> &prefixStr, string str){
        if(temp -> h.size() == 0){
            prefixStr.push_back(str);
            return;
        }
        
        if(temp -> isTerminal) prefixStr.push_back(str);
        
        for(auto x : temp -> h){
            char ch = x.first;
            str.push_back(ch);
            helper(temp -> h[ch],t,prefixStr,str);
            str.pop_back();
        }
    }
    void solve(string s, trie t, vector<vector<string>> &ans){
        int n = s.length();
        string str = "";
        for(int i = 0; i < n; i++){
            str.push_back(s[i]);
            
            node* temp = t.root;
            int m = str.size();
            vector<string> prefixStr;
            int j;
            for(j = 0; j < m; j++){
                char ch = str[j];
                if(temp -> h.count(ch)) temp = temp -> h[ch];
                else{
                    prefixStr.push_back("0");
                    ans.push_back(prefixStr);
                    break;
                }
            }
            if(j == m){
                helper(temp,t,prefixStr,str);
                ans.push_back(prefixStr);
            }
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        trie t;
        for(int i = 0; i < n; i++) t.insert(contact[i]);
        
        vector<vector<string>> ans;
        
        solve(s,t,ans);
        
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
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends