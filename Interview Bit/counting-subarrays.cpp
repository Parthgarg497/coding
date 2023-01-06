/*
    name= counting subarrays
    link- https://www.interviewbit.com/problems/counting-subarrays/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::solve(vector<int> &A, int B) {
    int n= A.size();
    int i=0,j=0;
    int sum=0;
    int count=0;
    for(i=0; i<n;i++)
    {
        sum+= A[i];
        while(sum >= B)
        {
            sum-= A[j];
            j++;
        }
        count+= i-j+1;
    }
    return count;
    
}
