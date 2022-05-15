// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    static bool comp(pair<int,char> a, pair<int,char> b){
        return a.first > b.first;
    }
    string rearrangeString(string str)
    {
        //code here
        int n = str.length();
        
        unordered_map<char,int> h;
        for(int i = 0; i < n; i++) h[str[i]]++;
        
        vector<pair<int,char>> v;
        
        for(auto &node : h) v.push_back(make_pair(node.second,node.first));
        
        int m = v.size();
        string temp = "";
        int i = 0;
        int j = 1;
        
        while(i < m && j < m){
            if(v[i].first < v[j].first) swap(v[i],v[j]);
            while(v[j].first > 0){
                temp.push_back(v[i].second);
                temp.push_back(v[j].second);
                v[i].first--;
                v[j].first--;
            }
            if(v[i].first == 0){
                i = j + 1;
                j = i + 1;
            }else if(v[j].first == 0) j++;
        }
        
        if(i >= m && j >= m) return temp;
        else{
            string ans = "";
            
            int len = temp.length();
            int p = 0;
            int q = 1;
            while(v[i].first > 0 && p < len && q < len){
                if(temp[p] != v[i].second && temp[q] != v[i].second){
                    ans.push_back(temp[p]);
                    ans.push_back(v[i].second);
                    v[i].first--;
                    p++;
                    q++;
                }else{
                    ans.push_back(temp[p]);
                    p++;
                    q++;
                }
            }
            while(p < len){
                ans.push_back(temp[p]);
                p++;
            }
            if(v[i].first == 0) return ans;
            else if(v[i].first == 1 && v[i].second != temp[len - 1]){
                ans.push_back(v[i].second);
                return ans;
            }
            return "-1";
        }
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