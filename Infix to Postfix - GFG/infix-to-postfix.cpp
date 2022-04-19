// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char> pile;
        string ans = "";
        
        for(int i = 0; s[i] != '\0'; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ans.push_back(s[i]);
            else if(s[i] == '(') pile.push(s[i]);
            else if(s[i] == ')'){
                while(!pile.empty() && pile.top() != '('){
                    ans.push_back(pile.top());
                    pile.pop();
                }
                pile.pop();
            }
            else if(s[i] == '^') pile.push(s[i]);
            else if(s[i] == '*' || s[i] == '/'){
                while(!pile.empty() && (pile.top() == '^' || pile.top() == '/' || pile.top() == '*')){
                    ans.push_back(pile.top());
                    pile.pop();
                }
                pile.push(s[i]);
            }
            else if(s[i] == '+' || s[i] == '-'){
                while(!pile.empty() && (pile.top() == '^' || pile.top() == '/' || pile.top() == '*' || pile.top() == '+' || pile.top() == '-')){
                    ans.push_back(pile.top());
                    pile.pop();
                }
                pile.push(s[i]);
            }
            
        }
        
        while(!pile.empty()){
            ans.push_back(pile.top());
            pile.pop();
        }
        
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends