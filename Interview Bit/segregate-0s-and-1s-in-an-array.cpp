/*
    name= Segregate 0s and 1s in an array
    link- https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

vector<int> Solution::solve(vector<int> &A) {
    int n= A.size();
    int i=0,j;
    while(i<n && A[i]!= 1)i++;
    j=i+1;
    while(j<n)
    {
        if(A[j]==0)
        {
            swap(A[i],A[j]);
            i++;
        }
        j++;
    }
    return A;
    
}
