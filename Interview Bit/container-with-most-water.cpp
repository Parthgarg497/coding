/*
    name= container with most water
    link- https://www.interviewbit.com/problems/container-with-most-water/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/


int Solution::maxArea(vector<int> &A) {
    int n= A.size();
    int l=0,r=n-1;
    int ans= 0;
    
    while(l<r)
    {
        ans= max(ans, (min(A[r],A[l]))*(r-l));
        if(A[l]<A[r]){
            l++;
        }    
        else{
            r--;
        }
    }
    return ans;
}
