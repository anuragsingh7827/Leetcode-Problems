class Solution {
public:
    vector<int> factorial(int n){
        vector<int> fact;
        fact.push_back(1);
        for(int i = 1; i <= n; i++) fact.push_back(i * fact[i - 1]);
        return fact;
    }
    string getPermutation(int n, int k) {
        vector<int> fact = factorial(n);

        map<int,int> h;
        for(int i = 1; i <= n; i++) h[i] = i;

        int i = 1;
        int target = 0;
        auto j = h.begin();
        string str = "";

        while(!h.empty()){
            target += fact[n - i];
            if(target >= k){
                auto node = *j;
                str.push_back(node.second + '0');
                target -= fact[n - i];
                h.erase(j);
                i++;
                j = h.begin();
            }else j++;
        }

        return str;
    }
};