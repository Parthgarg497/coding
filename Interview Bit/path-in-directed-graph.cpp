/*
    name= path in directed graph
    link- https://www.interviewbit.com/problems/path-in-directed-graph/
    author- Parth garg
    time complexity- o(v+e)
    space complexity- o(N) stack + o(N) vis + o(N*N) (in worst case for storing graph)
    method 1;
*/
void dfs(vector<vector<int>>&graph, int i,vector<int>&vis){
    vis[i] = 1;
    for(auto child :graph[i]){
        if(!vis[child]){
            dfs(graph, child, vis);
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>graph(A+1);
    vector<int>vis(A+1,0);
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
    }
    dfs(graph,1,vis);
    if(vis[A]==1) return 1;
    else return 0;
    
}


