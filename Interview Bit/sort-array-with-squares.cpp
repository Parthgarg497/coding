/*
    name= Sort array with squares!
    link- https://www.interviewbit.com/problems/sort-array-with-squares/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- merge both arrays;
*/

vector<int> Solution::solve(vector<int> &A) {
    int n= A.size();
    vector<int>res;
    
    int i,j;
    for(i=0;i<n;i++)
    {
        if(A[i]>= 0)break;
    }
    
    j= i-1;
    while(i<n && j>=0)
    {
        if(A[i]*A[i] < A[j]*A[j])
        {
            res.push_back(A[i]*A[i]);
            i++;
        }
        else 
        {
            res.push_back(A[j]*A[j]);
            j--;
        }
    }
    while(i<n)
    {
        res.push_back(A[i]*A[i]);
        i++;
    }
    while(j>=0)
    {
        res.push_back(A[j]*A[j]);
        j--;
    }
    
    return res;
    
}
