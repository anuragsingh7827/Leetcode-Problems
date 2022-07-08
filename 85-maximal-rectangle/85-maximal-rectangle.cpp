class Solution {
public:
    vector<int> NSR(vector<int> acc, int m){
        stack<int> s;
        vector<int> nsr(m);
        for(int j = m - 1; j >= 0; j--){
            if(!s.empty() && acc[s.top()] < acc[j]) nsr[j] = s.top();
            else if(s.empty()) nsr[j] = m;
            else if(!s.empty() && acc[s.top()] >= acc[j]){
                while(!s.empty() && acc[s.top()] >= acc[j]) s.pop();
                
                if(s.empty()) nsr[j] = m;
                else if(acc[s.top()] < acc[j]) nsr[j] = s.top();
            }
            s.push(j);
        }
        
        return nsr;
    }
    vector<int> NSL(vector<int> acc, int m){
        stack<int> s;
        vector<int> nsl(m);
        for(int j = 0; j < m; j++){
            if(!s.empty() && acc[s.top()] < acc[j]) nsl[j] = s.top();
            else if(s.empty()) nsl[j] = -1;
            else if(!s.empty() && acc[s.top()] >= acc[j]){
                while(!s.empty() && acc[s.top()] >= acc[j]) s.pop();
                
                if(s.empty()) nsl[j] = -1;
                else if(acc[s.top()] < acc[j]) nsl[j] = s.top();
            }
            s.push(j);
        }
        
        return nsl;
    }
    int MAH(vector<int> acc, int m){
        vector<int> nsr = NSR(acc,m);
        vector<int> nsl = NSL(acc,m);
        
        int maxi = INT_MIN;
        for(int j = 0; j < m; j++){
            int curArea = (nsr[j] - nsl[j] - 1) * acc[j];
            maxi = max(maxi,curArea);
        }
        
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int maxArea = 0;
        vector<int> acc(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0') acc[j] = 0;
                else acc[j] += 1;
            }
            maxArea = max(maxArea,MAH(acc,m));
        }
        
        return maxArea;
    }
};