
/*
    name= perfect peak of array
    link- https://www.interviewbit.com/problems/perfect-peak-of-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

int Solution::perfectPeak(vector<int> &A) {
    int n= A.size();
    vector<int>prefix(n);
    vector<int>Suffix(n);
    
    prefix[0]= A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]> prefix[i-1]) prefix[i]= A[i];
        else prefix[i]= prefix[i-1];
    }
    
    Suffix[n-1]= A[n-1];
    for(int i= n-2;i>=0;i--)
    {
        if(A[i]< Suffix[i+1]) Suffix[i]= A[i];
        else Suffix[i]= Suffix[i+1];
    }
    
    
    for(int i=1;i<n-1;i++)
    {
        if(prefix[i-1] < A[i] && Suffix[i+1] > A[i]) return 1;
    }
    return 0;
    
}
