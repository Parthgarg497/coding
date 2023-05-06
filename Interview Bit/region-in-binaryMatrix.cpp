/*
    name= region in binary matrix
    link- https://www.interviewbit.com/problems/region-in-binarymatrix/
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- bfs;
*/
int bfs(vector<vector<int> > &A, int x, int y){
    int m= A.size(),n= A[0].size();
    queue<pair<int,int>>q;
    q.push({x,y});
    int count =0;
    A[x][y] = 0;
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        count++;
        for(int i = -1;i<=1;i++){
            for(int j= -1;j<=1;j++){
                int newX= currX+i;
                int newY= currY+j;
                if(newX>=0 && newY>=0 && newX <m && newY <n && A[newX][newY] == 1){
                    q.push({newX,newY});
                    A[newX][newY] = 0;
                }
            }
        }
    }
    return count;
}

int Solution::solve(vector<vector<int> > &A) {
    int ans= 0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j] == 1){
                ans= max(ans, bfs(A,i,j));
            }
        }
    }
    return ans;
    
}
