// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        int n = str.length();
        
        unordered_map<char,int> h;
        for(int i = 0; i < n; i++) h[str[i]]++;
        
        int maxCnt = INT_MIN;
        char ch = '\0';
        for(auto &node : h){
            if(node.second > maxCnt){
                maxCnt = node.second;
                ch = node.first;
            }
        }
        
        char* arr = new char[n]{'\0'};
        
        int i = 0;
        while(h[ch] > 0 && i < n){
            arr[i] = ch;
            h[ch]--;
            i += 2;
        }

        if(i >= n){
            i = 1;
            h.erase(ch);
        }
        
        for(auto &node : h){
            char newCh = node.first;
            while(h[newCh] > 0 && i < n){
                arr[i] = newCh;
                h[newCh]--;
                i += 2;
                if(i >= n) i = 1;
            }

        }
        string ans = "";       
        for(int j = 0; j < n; j++){
            if(arr[j] == '\0') return "-1";
            else ans.push_back(arr[j]);
        }
        
        delete[] arr;
        arr = NULL;
        
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
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends