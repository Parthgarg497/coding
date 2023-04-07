/*
    name= water flow
    link- https://www.interviewbit.com/problems/water-flow/
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- dfs;
*/

void dfs(vector<vector<int> > &A,vector<vector<int>>&vis, int i, int j){
    int n= A.size();
    int m= A[0].size();
    vis[i][j] =1;
    
    if(i-1 >=0 && vis[i-1][j]==0 && A[i-1][j] >= A[i][j]){
        dfs(A,vis,i-1,j);
    }
    if(i+1 <n && vis[i+1][j]==0 && A[i+1][j] >= A[i][j]){
        dfs(A,vis,i+1,j);
    }
    if(j-1 >=0 && vis[i][j-1]==0 && A[i][j-1] >= A[i][j]){
        dfs(A,vis,i,j-1);
    }
    if(j+1 <m && vis[i][j+1]==0 && A[i][j+1] >= A[i][j]){
        dfs(A,vis,i,j+1);
    }
    
}

int Solution::solve(vector<vector<int> > &A) {
    int n= A.size();
    int m= A[0].size();
    vector<vector<int>>visBlue(n,vector<int>(m,0));
    vector<vector<int>>visRed(n,vector<int>(m,0));
    
    for(int i=0;i<m;i++){
        if(!visBlue[0][i])
            dfs(A,visBlue,0,i);
        if(!visRed[n-1][i])
            dfs(A,visRed,n-1,i);
    }
    for(int i=1;i<n;i++){
        if(!visBlue[i][0])
            dfs(A,visBlue,i,0);
        if(!visRed[n-i-1][m-1])
            dfs(A,visRed,n-i-1,m-1);
    }
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visBlue[i][j] ==1 && visRed[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
