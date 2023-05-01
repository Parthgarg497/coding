/*
    name= Largest Distance between nodes of a Tree
    link- https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(height of tree)
    method 1- for every node find the max deepest node and second deepest node and update the sum of length of both in answer variable;
    method 2- find a fartest node from root and call it x and find the fartest with respect to x using any bfs/dfs algorithm
*/

int findHeight(vector<vector<int>>&graph, int node,int parent, int &ans){
    if(graph[node].size()==1 && graph[node][0] == parent){
        return 1;
    }
    int maxi=0,nextMaxi=0;
    for(auto child : graph[node]){
        if(child == parent ) continue;
        int x= findHeight(graph, child, node, ans);
        if(x> maxi){
            nextMaxi = maxi;
            maxi= x;
        }
        else if(x> nextMaxi){
            nextMaxi = x;
        }
    }
    ans = max(ans, maxi+ nextMaxi);
    return maxi+1;
}

int Solution::solve(vector<int> &A) {
    int n= A.size();
    vector<vector<int>>graph(n);
    int root;
    for(int i=0;i<n;i++){
        if(A[i]== -1) {root= i; continue;}
        graph[i].push_back(A[i]);
        graph[A[i]].push_back(i);
    }
    int ans= 0;
    findHeight(graph, root,-1,ans);
    return ans;
    
}
