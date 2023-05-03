/*
    name= delete edge
    link- https://www.interviewbit.com/problems/delete-edge/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(height of tree)
    method 1;
*/

int findSum(vector<vector<int>>&tree, vector<int>&A,int node,int parent, long long total,long long &ans){
    long long sum=0;
    for(auto child : tree[node]){
        if(child == parent)continue;
        sum+= findSum(tree, A,child, node,total,ans);
    }
    
    ans= max(ans, (sum+A[node-1])*1LL*(total- sum- A[node-1]));
    
    return sum+ A[node-1];
    
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n= A.size();
    vector<vector<int>>tree(n+1);
    for(int i=0;i<B.size();i++){
        tree[B[i][0]].push_back(B[i][1]);
        tree[B[i][1]].push_back(B[i][0]);
    }
    long long total = 0;
    for(int i=0;i<n;i++)total+= A[i];
    long long ans= 0;
    
    findSum(tree, A,1,-1,total,ans);
    int m= 1e9+ 7;
    return (ans%m);
    
}
