/*
    name= knight on chess board
    link- https://www.interviewbit.com/problems/knight-on-chess-board/
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- level wise traversal;
*/
int minMoves(int srcX, int srcY, int endX, int endY, int A, int B){
    if(endX<=0 || endX >A || endY <=0 || endY > B) return -1;
    
    int dx[]= {-2,-2,2,2,-1,-1,1,1};
    int dy[]= {-1,1,-1,1,-2,2,-2,2};

    queue<pair<int,int>>q;
    q.push({srcX,srcY});
    vector<vector<int>>vis(A+1,vector<int>(B+1,0));
    vis[srcX][srcY] = 1;
    while(!q.empty()){
        int topX = q.front().first;
        int topY = q.front().second;
        q.pop();
        
        for(int i= 0;i<8;i++){
            int newX = topX + dx[i];
            int newY = topY + dy[i];
            if(newX <=0 || newX > A || newY <=0 || newY > B) continue;
            if(vis[newX][newY]==0){
                vis[newX][newY] = vis[topX][topY]+1;
                q.push({newX,newY});
            }
        }
        
    }
    return vis[endX][endY]-1;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    return minMoves(C,D,E,F,A,B);
}
