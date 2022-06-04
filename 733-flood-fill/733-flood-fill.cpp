class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        bool** visited = new bool*[m];
        for(int i = 0; i < m; i++) visited[i] = new bool[n];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) visited[i][j] = false;
        }
        visited[sr][sc] = true;
        
        int di[4] = {0,-1,0,1};
        int dj[4] = {1,0,-1,0};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            int I = p.first;
            int J = p.second;
            
            int oldColor = image[I][J];
            image[I][J] = newColor;
            
            for(int k = 0; k < 4; k++){
                int i = I + di[k];
                int j = J + dj[k];
                if(i < 0 || i >= m || j < 0 || j >= n) continue;
                else if(!visited[i][j] && image[i][j] == oldColor){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        
        return image;
    }
};