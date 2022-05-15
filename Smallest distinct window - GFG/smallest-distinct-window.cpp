// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        int n = str.length();
        
        unordered_map<char,int> h;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(h[str[i]] == 0){
                h[str[i]]++;
                cnt++;
            }
        }
        
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        while(j < n){
            if(h[str[j]] == 1) cnt--;
            h[str[j]]--;
            
            if(cnt > 0) j++;
            else if(cnt == 0){
                while(cnt == 0){
                    ans = min(ans,j - i + 1);
                    h[str[i]]++;
                    if(h[str[i]] == 1) cnt++;
                    i++;
                }
                j++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends