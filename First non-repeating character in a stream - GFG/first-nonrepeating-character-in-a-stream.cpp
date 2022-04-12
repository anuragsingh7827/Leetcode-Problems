// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> f;
		    queue<char> q;
		    
		    string ans = "";
		    for(int i = 0; A[i] != '\0'; i++){
		        f[A[i]]++;
		        if(f[A[i]] == 1) q.push(A[i]);
		        
		        if(q.empty()) ans.push_back('#');
		        else{
		            while(!q.empty() && f[q.front()] > 1) q.pop();
		            
		            if(q.empty()) ans.push_back('#');
		            
		            else if(f[q.front()] == 1) ans.push_back(q.front());
		        }
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends