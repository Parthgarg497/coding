/*
    name= path with good nodes
    link- https://www.interviewbit.com/problems/path-with-good-nodes/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

int dfs(vector<vector<int>>&graph, int node ,vector<int> &A, int c, int parent){
    if(A[node-1] == 1) {
        c--;
    }
    if(graph[node].size()==1 && graph[node][0] == parent){
        if(c>=0){
            return 1;
        }
        return 0;
    }
    
    int ans= 0;
    for(auto child : graph[node]){
        if(child == parent)continue;
       ans +=  dfs(graph, child, A, c, node);
    }
    return ans;
    
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n= A.size();
    vector<vector<int>>graph(n+1);
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    return dfs(graph, 1,A,C,-1);
    
    
}
