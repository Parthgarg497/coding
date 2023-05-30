/*
    name= Possibility of finishing all courses given pre-requisites
    link- https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
    author- Parth garg
    time complexity- o(v+e)
    space complexity- o(v)
    method 1- take 2 vis array one for calling dfs for unvisited nodes (vis)
            another for checing cycle on a particular dfs call (dfsVis);
*/

int dfs(unordered_map<int,vector<int>>&graph, vector<int>&vis,vector<int>&dfsVis, int src){
    vis[src] = 1;
    dfsVis[src] = 1;
    
    for(auto child : graph[src]){
        if(!vis[child]){
            if(dfs(graph, vis,dfsVis,child)) return 1;
        }
        else if(dfsVis[child]){
            return 1;
        }
    }
    dfsVis[src] = 0;
    return 0;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int>vis(A+1,0);
    vector<int>dfsVis(A+1,0);
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<B.size();i++){
        mp[B[i]].push_back(C[i]);
    }
    
    for(int i=1;i<A+1;i++){
        if(!vis[i]){
            // dfs function returns 1 if there is a cycle in graph
            if(dfs(mp,vis,dfsVis,i)) return 0;
        }
    }    
    return 1;
}
