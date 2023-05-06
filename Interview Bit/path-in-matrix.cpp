/*
    name= path in matrix
    link- https://www.interviewbit.com/problems/path-in-matrix/
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- dfs/bfs;
*/
bool dfs(vector<vector<int> > &A ,int i, int j){
    if(A[i][j] == 2) return true;
    
    int arr1[]= {-1,0,1,0};
    int arr2[]= {0,-1,0,1};
    for(int k=0;k<4;k++){
        int newX= i+ arr1[k];
        int newY= j+ arr2[k];
        if(newX>=0 && newY>=0 && newX < A.size() && newY < A[0].size() && (A[newX][newY] == 2 ||A[newX][newY] == 3)) {
            if(A[newX][newY] == 2) return true;
            A[newX][newY] = 0;
            // cout<<newX<<" "<<newY<<endl;
            if(dfs(A,newX,newY)) return true;
        }
    }
    return false;
}

int Solution::checkPath(vector<vector<int> > &A) {
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j] == 1){
                A[i][j]= 0;
                return (dfs(A,i,j)== true) ? 1 : 0;
            }
        }
    } 
    return 0;  
}