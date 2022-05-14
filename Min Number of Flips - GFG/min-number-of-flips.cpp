// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    
    int op1 = 0;
    for(int i = 0; i < n; i++){
        if((i&1 && S[i] == '0') || (!(i&1) && S[i] == '1')) op1++;
    }
    
    int op2 = 0;
    for(int i = 0; i < n; i++){
        if((i&1 && S[i] == '1') || (!(i&1) && S[i] == '0')) op2++;
    }
    
    return min(op1,op2);
}