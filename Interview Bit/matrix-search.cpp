/*
    name= matrix search 
    link- https://www.interviewbit.com/problems/matrix-search/
    author- Parth garg
    time complexity- o(log(n*m))
    space complexity- o(1)
    method 1;
*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n= A.size(),m= A[0].size();
    int l= 0,r= (n*m) -1;
    int x= m;
    
    while(l<r){
        int mid= l+ (r-l)/2;
        int i= mid/x,j= mid%x;
            
        if(A[i][j]< B){
            l= mid+1;
        }
        else {
            r= mid;
        }
    }
    if(A[l/x][l%x] == B) return 1;
    return 0;
}
