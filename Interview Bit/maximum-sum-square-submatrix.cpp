/*
    name= maximum sum square submatrix
    link-  https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(n^2)
    method 1- precomputation;
*/

int Solution::solve(vector<vector<int> > &A, int B) {
    int n= A.size();
    vector<vector<int>>rowSum(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        rowSum[i][0]= A[i][0];
        for(int j= 1; j<n;j++)
        {
            rowSum[i][j]= rowSum[i][j-1]+ A[i][j];
        }
    }
    int ans= INT_MIN;
    for(int i=0;i<=n-B;i++)
    {
        for(int j=0;j<=n-B;j++)
        {
            int sum=0;
            for(int k=i;k<i+B;k++)
            {
                int x= j-1 >=0 ? rowSum[k][j-1] :0 ;
                sum+= (rowSum[k][j+B-1]- x) ;
            }
            ans= max(ans,sum);
        }
    }
    return ans;
}
