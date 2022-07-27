class Solution {
public:
    int minRemovals(string s){
        stack<char> pile;
        int n = s.size();
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '(') pile.push(ch);
            else if(ch == ')'){
                if(!pile.empty() && pile.top() == '(') pile.pop();
                else pile.push(')');
            }
        }
        
        return pile.size();
    }
    void solve(string s, int removals, unordered_map<string,bool> &vis, vector<string> &ans){
        if(vis[s]) return;
        
        vis[s] = true;
        
        if(removals == 0){
            if(minRemovals(s) == 0){
                ans.push_back(s);
            }
            return;
        }
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            string str = s.substr(0,i) + s.substr(i + 1,n - i - 1);
            solve(str,removals - 1,vis,ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        
        int removals = minRemovals(s);
        
        vector<string> ans;
        unordered_map<string,bool> vis;
        solve(s,removals,vis,ans);
        
        if(ans.empty()) ans.push_back(s);
        return ans;
    }
};