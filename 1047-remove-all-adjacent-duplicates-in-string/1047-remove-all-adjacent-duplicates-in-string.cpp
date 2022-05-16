class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        
        stack<char> pile;
        int i = 0;
        while(i < n){
            if(i + 1 < n){
                if(s[i] == s[i + 1]) i += 2;
                else if(s[i] != s[i + 1]){
                    if(!pile.empty()){
                        if(pile.top() == s[i]){
                            pile.pop();
                            i++;
                        }else if(pile.top() != s[i]){
                            pile.push(s[i]);
                            i++;
                        }
                    }else if(pile.empty()){
                        pile.push(s[i]);
                        i++;
                    }
                }
            }else if(i + 1 >= n){
                if(!pile.empty()){
                    if(pile.top() == s[i]){
                        pile.pop();
                        i++;
                    }else if(pile.top() != s[i]){
                        pile.push(s[i]);
                        i++;
                    }
                }else if(pile.empty()){
                    pile.push(s[i]);
                    i++;
                }
            }
        }
        string ans = "";
        while(!pile.empty()){
            ans.push_back(pile.top());
            pile.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};