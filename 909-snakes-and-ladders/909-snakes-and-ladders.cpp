class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int m = (n * n) + 1;
        
        int* arr = new int[m];
        
        int cnt = 1;
        int flag = 0;
        for(int i = n - 1; i >= 0; i--){
            if(flag == 0){
                for(int j = 0; j < n; j++){
                    arr[cnt] = board[i][j];
                    cnt++;
                }
                flag = 1;
            }else{
                for(int j = n - 1; j >= 0; j--){
                    arr[cnt] = board[i][j];
                    cnt++;
                }
                flag = 0;
            }
        }
        
        vector<int> moves(m,INT_MAX);
        
        queue<int> q;
        q.push(1);
        moves[1] = 0;
        
        while(!q.empty()){
            int cell = q.front();
            q.pop();
            
            for(int i = 1; i <= 6; i++){
                if(cell + i < m){
                    if(arr[cell + i] != -1){
                        if(moves[cell] + 1 < moves[arr[cell + i]]){
                            moves[arr[cell + i]] = moves[cell] + 1;
                            q.push(arr[cell + i]);
                        }
                    }else{
                        if(moves[cell] + 1 < moves[cell + i]){
                            moves[cell + i] = moves[cell] + 1;
                            q.push(cell + i);
                        }
                    }
                }
            }
        }
        
        if(moves[m - 1] == INT_MAX) return -1;
        return moves[m - 1];
    }
};