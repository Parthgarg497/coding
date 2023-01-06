/*
    name= maximum ones after modification
    link- https://www.interviewbit.com/problems/maximum-ones-after-modification/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1->  2 pointers;
*/

int Solution::solve(vector<int> &A, int k) {
    int i=0,j=0;
    int n= A.size();
    int countZeros= A[0]==0 ? 1 : 0 ;
    int ans=min(k,n);
    
    while(j<n && i<n)
    {
        while(j<n-1)
        {
            if(countZeros> k) break;
            j++;
            if(A[j]==0) countZeros++;
            if(j==n-1 && countZeros <=k){
                j++;
                break;
            }
        }
        ans= max(ans, j-i);
        i++;
        if(i<n && A[i-1] == 0) countZeros--;
    }
    return ans;
    
}
