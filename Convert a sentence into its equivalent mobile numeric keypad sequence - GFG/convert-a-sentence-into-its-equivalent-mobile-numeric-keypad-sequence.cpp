// { Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string printSequence(string S)
{
    //code here.
    int n = S.length();
    vector<string> keypad{"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    
    int keypadSize = 10;
    
    string ans = "";
    for(int i = 0; i < n; i++){
        char ch = S[i];
        if(ch == ' ') ans.push_back('0');
        else{
            int idx = 9;
            for(int j = 1; j < keypadSize; j++){
                if(keypad[j][0] > ch){
                    idx = j - 1;
                    break;
                }
            }
            for(int j = 1; j <= S[i] - keypad[idx][0] + 1; j++) ans.push_back(idx + '0');
        }
        
    }
    
    return ans;
}