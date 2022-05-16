// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    static bool comp(pair<string,string> a, pair<string,string> b){
        return a.first < b.first;
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        
        vector<pair<string,string>> v(n);
        
        for(int i = 0; i < n; i++){
            string word = string_list[i];
            string wordCopy = word;
            sort(wordCopy.begin(),wordCopy.end());
            v[i] = make_pair(wordCopy,word);
        }
        
        stable_sort(v.begin(),v.end(),comp);

        vector<vector<string>> ans;
        
        vector<string> group;
        group.push_back(v[0].second);
        for(int i = 1; i < n; i++){
            if(v[i].first == v[i - 1].first) group.push_back(v[i].second);
            else{
                ans.push_back(group);
                group.erase(group.begin(),group.end());
                group.push_back(v[i].second);
            }
        }
        ans.push_back(group);
        
        sort(ans.begin(),ans.end());
        
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends