/*
    name= first missing integer
    link-  https://www.interviewbit.com/problems/first-missing-integer/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::firstMissingPositive(vector<int> &A) {
    int n= A.size();
    
    for(int i=0;i<n;i++)
    {
        int element= A[i];
        int chair= element-1;
        if(chair >=0 && chair < n){
            if(A[chair] != A[i])
            {
                swap(A[chair],A[i]);
                i--;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(A[i] != i+1) return i+1;
    }
    return n+1;
    
}
