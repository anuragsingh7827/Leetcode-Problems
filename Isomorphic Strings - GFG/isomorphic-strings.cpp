// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n = str1.length();
        int m = str2.length();
        
        int h1[MAX_CHARS] = {0};
        int h2[MAX_CHARS] = {0};
        
        for(int i = 0; i < n; i++) h1[str1[i]]++;
        for(int i = 0; i < m; i++) h2[str2[i]]++;
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(h1[str1[i]] != h2[str2[j]]) return false;
            i++;
            j++;
        }
        
        if(i < n || j < m) return false;
        
        return true;
        
    }
};
// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends