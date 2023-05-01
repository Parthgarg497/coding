/*
    name= good graph
    link- https://www.interviewbit.com/problems/good-graph/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- use dfs and visited array , when returning in recursive calls don't forgot to change the adj[node] = 1 . 
            dfs function returns if that series of nodes are good nodes or not 
            if dfs returns 1 it means they are not good nodes and if it returns 0 it means they are good nodes. ;
*/

int dfs(vector<int>&adj, vector<int>&vis, int node){
    if(adj[node] == 1){
        vis[node] = 1;
        return 0;
    }
    if(vis[node] == 1){
        adj[node]= 1;
        return 1;
    }
    
    vis[node] = 1;
    int res= dfs(adj,vis,adj[node]);
    adj[node] = 1;
    return res;
}

int Solution::solve(vector<int> &A) {
    int count =0;
    int n= A.size();
    vector<int>adj(n+1);
    for(int i=1;i<=n;i++){
        adj[i]= A[i-1];
    }
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(adj, vis, i)){
                count++;
            }
        }
    }
    return count;
}
