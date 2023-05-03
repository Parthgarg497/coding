/*
    name= two teams
    link- https://www.interviewbit.com/problems/two-teams/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- make bipartite graph ;
*/
bool dfs(vector<vector<int>>&graph, vector<int>&color, int node){
    
    for(auto child : graph[node]){
        if(color[child] == -1){
            if(color[node] == 1){
                color[child]= 2;
            }
            else if(color[node] ==2){
                color[child]= 1;
            }
            if(!dfs(graph,color,child)) return 0;
        }
        else{
            if(color[child]== color[node]) return 0;
        }
    }
    return 1;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>color(A+1,-1);
    vector<vector<int>>graph(A+1);
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    for(int i=1 ;i<=A;i++){
        if(color[i] == -1){
            color[i] = 1;
            if(!dfs(graph,color,i)) return 0;
        }
    }
    return 1;
    
}
