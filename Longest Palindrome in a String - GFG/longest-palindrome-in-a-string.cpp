// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.length();
        
        int len = INT_MIN;
        string ans;
        for(int i = 0; i < n; i++){
            string curr = "";
            curr.push_back(S[i]);
            int j = i - 1;
            int k = i + 1;
            while(j >= 0 && k < n && S[j] == S[k]){
                curr = string(1,S[j]) + curr;
                curr.push_back(S[k]);
                j--;
                k++;
            }
            int currLen = curr.length();
            if(currLen > len){
                len = curr.length();
                ans = curr;
            }
            if(i > 0 && S[i] == S[i - 1]){
                curr = "";
                curr.push_back(S[i - 1]);
                curr.push_back(S[i]);
                j = i - 2;
                k = i + 1;
                while(j >= 0 && k < n && S[j] == S[k]){
                    curr = string(1,S[j]) + curr;
                    curr.push_back(S[k]);
                    j--;
                    k++;
                }
                currLen = curr.length();
                if(currLen > len){
                    len = curr.length();
                    ans = curr;
                }
            }

        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends