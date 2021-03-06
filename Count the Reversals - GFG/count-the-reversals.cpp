// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n = s.length();
    if(n & 1) return -1;

    int invalidOpen = 0;
    int invalidClose = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '{') invalidOpen++;
        else{
            if(invalidOpen > 0) invalidOpen--;
            else invalidClose++;
        }
    }

    int ans = 0;
    invalidOpen & 1 ? ans += (invalidOpen / 2) + 1 : ans += invalidOpen / 2;
    invalidClose & 1 ? ans += (invalidClose / 2) + 1 : ans += invalidClose / 2;
    
    return ans;
}