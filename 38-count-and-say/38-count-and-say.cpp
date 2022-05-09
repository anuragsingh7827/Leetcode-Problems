class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";
        
        string temp = countAndSay(n - 1);
        
        int cnt = 1;
        char curr = temp[0];
        int len = temp.length();
        string ans = "";
        for(int i = 1; i < len; i++){
            if(temp[i] == curr) cnt++;
            else{
                ans += to_string(cnt);
                ans.push_back(curr);
                cnt = 1;
                curr = temp[i];
            }
        }
        ans += to_string(cnt);
        ans.push_back(curr);
        return ans;
    }
};