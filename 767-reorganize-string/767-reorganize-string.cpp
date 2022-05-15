class Solution {
public:
    static bool comp(pair<int,char> a, pair<int,char> b){
        return a.first > b.first;
    }
    string reorganizeString(string str) {
        int n = str.length();
        
        unordered_map<char,int> h;
        for(int i = 0; i < n; i++) h[str[i]]++;
        
        vector<pair<int,char>> v;
        
        for(auto &node : h) v.push_back(make_pair(node.second,node.first));
        
        sort(v.begin(),v.end(),comp);
        
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
            if(temp == "") return "";
            
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
            return "";
        }

    }
};