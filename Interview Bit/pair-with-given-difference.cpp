/*
    name= pair with given difference
    link- https://www.interviewbit.com/problems/pair-with-given-difference/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

int Solution::solve(vector<int> &A, int B) {
    if(A.size()==1) return 0; 
    int n= A.size();
    sort(A.begin(),A.end());
    int l=0,r=1;
    while(r<n)
    {
        if( r==l || A[r]-A[l] < abs(B)) r++;
        else if(A[r]-A[l] >abs(B)) l++;
        else return 1;
    }
    return 0;
}
