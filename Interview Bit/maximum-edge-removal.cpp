/*
    name= maximum edge removal
    link-  https://www.interviewbit.com/problems/maximum-edge-removal/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/
int ans=0;
int dfs(vector<vector<int>>&graph, int node){
    int nodes=1;
    for(auto child: graph[node]){
        if(child == node) continue;
        nodes+= dfs(graph,child);
    }
    if(nodes%2 ==0){
        ans++;
        return 0;
    }
    else{
        return nodes;
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1);
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
    }
    
    ans=0;
    int nodes= dfs(graph, 1);
    ans--;
    return ans;
}
