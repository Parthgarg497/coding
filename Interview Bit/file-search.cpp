/*
    name= file search
    link- https://www.interviewbit.com/problems/file-search/
    author- Parth garg
    time complexity- o(v+e)
    space complexity- o(v)
    method 1;
*/
void bfs(vector<vector<int>>&graph, vector<int>&vis, int node){
    queue<int>q;
    q.push(node);
    
    while(!q.empty()){
        int nd= q.front();
        q.pop();
        vis[nd] = 1;
        for(auto child : graph[nd]){
            if(!vis[child]){
                q.push(child);
            }
        }
    }
}
int Solution::breakRecords(int A, vector<vector<int> > &B) {
    vector<vector<int>>graph(A+1);
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    vector<int>vis(A+1,0);
    int count =0;
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            bfs(graph,vis,i);
            count++;
        }
    }
    return count;
    
}
