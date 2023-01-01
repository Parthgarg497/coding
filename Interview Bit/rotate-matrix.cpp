/*
    name= rotate matrix
    link- https://www.interviewbit.com/problems/rotate-matrix/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(1)
    method 1;
*/

void Solution::rotate(vector<vector<int> > &A) {
    
    int n= A.size();
    for(int i=0;i<n/2;i++)
    {
        for(int j=i; j< n-1-i; j++)
        {
            swap(A[i][j], A[j][n-1-i]);
            swap(A[i][j], A[n-1-i][n-1-j]);
            swap(A[i][j], A[n-1-j][i]);
        }
    }
    return;
}
