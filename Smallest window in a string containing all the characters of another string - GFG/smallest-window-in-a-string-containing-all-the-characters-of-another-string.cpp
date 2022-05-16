// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length();
        int m = p.length();
        
        unordered_map<char,int> h;
        for(int i = 0; i < m; i++) h[p[i]]++;
        
        int cnt = h.size();
        int len = INT_MAX;
        int start = -1;
        int end = -1;
        int i = 0;
        int j = 0;

        while(j < n){
            if(h.count(s[j])){
                h[s[j]]--;
                if(h[s[j]] == 0) cnt--;
            }
            if(cnt > 0) j++;
            else if(cnt == 0){
                while(cnt == 0){
                    if(j - i + 1 < len){
                        len = j - i + 1;
                        start = i;
                        end = j;
                    }
                    if(h.count(s[i])){
                        h[s[i]]++;
                        if(h[s[i]] > 0) cnt++;
                    }
                    i++;
                }
                j++;
            }
        }
        
        if(start == -1 || end == -1) return "-1";
        
        string ans = "";
        for(int k = start; k <= end; k++) ans.push_back(s[k]);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends