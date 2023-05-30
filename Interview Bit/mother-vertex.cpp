/*
    name= mother vertex
    link- https://www.interviewbit.com/problems/mother-vertex/
    author- Parth garg
    time complexity- o(v+e)
    space complexity- o(v)
    method 1;
*/
void dfs(unordered_map<int,vector<int>>&graph, vector<int>&vis, int src){
    if(vis[src]==1) return;
    vis[src] = 1;
    for(auto child : graph[src]){
        dfs(graph,vis, child);
    }
}
int Solution::motherVertex(int A, vector<vector<int> > &B) {
    int mother;
    unordered_map<int,vector<int>>graph;
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
    }
    vector<int>vis(A+1,0);
    
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            mother= i;
            dfs(graph,vis,i);
        }
    }
    
    for(int i=0;i<=A;i++){
        vis[i]= 0;
    }
    dfs(graph, vis,mother);
    for(int i=1;i<=A;i++){
        if(vis[i]== 0) return 0;
    }
    return 1;
}
