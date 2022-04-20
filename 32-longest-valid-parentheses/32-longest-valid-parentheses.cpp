class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pile;
        pile.push(-1);
        int ans = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == '(') pile.push(i);
            else{
                pile.pop();
                if(pile.empty()) pile.push(i);
                else ans = max(ans,i - pile.top());
            }
        }
        return ans;
    }
};