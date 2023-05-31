/*
    name= black shapes
    link- https://www.interviewbit.com/problems/black-shapes/
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- graph traversal bfs/dfs;
*/
void bfs(vector<string> &A, vector<vector<int>>&vis, int x, int y){
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    int n= A.size();
    int m = A[0].size();
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        int topX = q.front().first;
        int topY = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int newX = topX+dx[i];
            int newY = topY+dy[i];
            if(newX <0 || newY <0 || newX >=n || newY >= m ) continue;
            if(A[newX][newY] == 'X' && vis[newX][newY] == 0){
                vis[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
    }
}

int Solution::black(vector<string> &A) {
    int n= A.size(),m= A[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int count =0;
    for(int i=0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(!vis[i][j] && A[i][j] == 'X'){
                bfs(A,vis,i,j);
                count++;
            }
        }
    }
    return count;
}
