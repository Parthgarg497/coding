/*
    name= word search board
    link- https://www.interviewbit.com/problems/word-search-board/
    author- Parth garg
    time complexity- o((n*m)*(n*m))
    space complexity- o(n*m) (stack)
    method 1;
*/

bool dfs(vector<string> &A, string B, int i, int j, int k){
    bool ans= true;
    if(k== B.length()) return true;
    if(i-1 >= 0 && A[i-1][j] == B[k]){
        ans = ans && dfs(A,B,i-1,j,k+1);
        if(ans== true) return true;
    }
    ans= true;
    if(i+1 < A.size() && A[i+1][j] == B[k]){
        ans= ans && dfs(A,B,i+1,j,k+1);
        if(ans== true) return true;
    }
    ans= true;
    if(j-1 >=0 && A[i][j-1] == B[k]){
        ans= ans && dfs(A,B,i,j-1,k+1);
        if(ans== true) return true;
    }
    ans= true;
    if(j+1 < A[0].length() && A[i][j+1] == B[k]){
        ans= ans && dfs(A,B,i,j+1,k+1);
        if(ans == true) return true;
    } 
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    bool ans= false;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].length();j++){
            if(A[i][j] == B[0]){
                if(dfs(A,B,i,j,1)) return 1;
            }
        }
    }
    return 0;
}
