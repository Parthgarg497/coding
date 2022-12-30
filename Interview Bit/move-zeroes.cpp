/*
    name= move zeroes
    link- https://www.interviewbit.com/problems/move-zeroes/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/


vector<int> Solution::solve(vector<int> &a) {
    int n= a.size();
    int i=0,j;
    while(i<n)
    {
        if(a[i]==0) break; 
        i++;
    }
    if(i>=n-1) return a;
    j=i+1; 
    while(j<n)
    {
        if(a[j]!=0)
        {
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
    return a;
}
