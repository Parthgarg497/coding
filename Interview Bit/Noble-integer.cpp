/*
    name= noble integer
    link- https://www.interviewbit.com/problems/noble-integer/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int n= A.size();
    
    for(int i= 0; i<n;i++)
    {
        while(i<n-1 && A[i]== A[i+1]) i++;
        if(A[i]== n-i-1) return 1;
    }
    return -1;
    
}
