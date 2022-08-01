class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";
        
        unordered_map<char,bool> mp1, mp2, mp3;
        for(int i = 0; i < 20; i++) mp1[row1[i]] = true;
        for(int i = 0; i < 18; i++) mp2[row2[i]] = true;
        for(int i = 0; i < 14; i++) mp3[row3[i]] = true;
        
        int n = words.size();
        vector<string> ans;
        for(int i = 0; i < n; i++){
            int flag1 = 0;
            int flag2 = 0;
            int flag3 = 0;
            
            string s = words[i];
            int m = s.size();
            
            if(mp1[s[0]]) flag1 = 1;
            else if(mp2[s[0]]) flag2 = 1;
            else if(mp3[s[0]]) flag3 = 1;
            
            int j;
            for(j = 1; j < m; j++){
                if(flag1 == 1 && mp1[s[j]] == false) break;
                else if(flag2 == 1 && mp2[s[j]] == false) break;
                else if(flag3 == 1 && mp3[s[j]] == false) break;
            }
            
            if(j == m) ans.push_back(s);
        }
        
        return ans;
    }
};