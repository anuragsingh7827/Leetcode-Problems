// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string str = "";
        for(int i = 0; i < D; i++) str.push_back('9');
        
        int diff = (9 * D) - S;
        if(diff < 0) return "-1";
        for(int i = 0; i < D; i++){
            if(i == 0){
                str[0] = 9 - min(diff,8) + '0';
                diff -= min(diff,8);
            }else{
                str[i] = 9 - min(diff,9) + '0';
                diff -= min(diff,9);
            }
        }
        
        return str;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends