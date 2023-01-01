/*
    name= next permutation
    link- https://www.interviewbit.com/problems/next-permutation/
    author- Parth garg
    time complexity- o(n)+ o(logn) - worst case
    space complexity- o(1)
    method 1; 
*/


vector<int> Solution::nextPermutation(vector<int> &A) {
    if(A.size()<=1) return A;
    
    int n= A.size();
    int i;
    for(i=n-2;i>=0;i--)
    {
        if(A[i]< A[i+1])
        {
            break;
        }
    }
    int l=i+1,r= n-1;
    while(l<r)
    {
        swap(A[l],A[r]);
        l++;r--;
    }
    if(i<0) return A;
    
    l= i+1;r=n-1;
    int target= A[i];
    while(l<r)
    {
        int mid= l+ (r-l+1)/2;
        if(A[mid] <= target)
        {
            l= mid;
        }
        else r= mid-1;
    }
    while(l<n && A[l] <= target) l++;
    
    swap(A[i],A[l]);
    return A;
    
}
