/*
    name= cycle in undirected graph
    link- https://www.interviewbit.com/problems/cycle-in-undirected-graph/
    author- Parth garg
    time complexity- o(v+e);
    space complexity- o(v);
    method 1;
*/
int dfs(vector<vector<int>>&graph, int src, vector<int>&vis, int parent){
    if(vis[src] == 1) return 1;
    vis[src] = 1;
    for(auto child : graph[src]){
        if(child != parent && dfs(graph,child, vis,src)) return 1;
    }
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>graph(A+1);
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    vector<int>vis(A+1, 0);
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            if(dfs(graph,i,vis,-1)) return 1;
        }
    }
    return 0;
}
