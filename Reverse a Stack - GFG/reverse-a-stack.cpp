// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void atEnd(stack<int> &s, int temp){
        if(s.empty()){
            s.push(temp);
            return;
        }
        
        int x = s.top();
        s.pop();
        atEnd(s,temp);
        s.push(x);
        
    }
    stack<int> Reverse(stack<int> St){
        
        if(St.empty()){
            return St;
        }
        
        int temp = St.top();
        St.pop();
        
        stack<int> s = Reverse(St);
        atEnd(s,temp);
        return s;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        stack<int> ans=ob.Reverse(St);
        vector<int> v;
        while(ans.size()){
            v.push_back(ans.top());
            ans.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<N;i++){
            cout<<v[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends