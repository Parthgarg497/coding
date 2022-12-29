/*
    name= anti diagonals
    link- https://www.interviewbit.com/problems/anti-diagonals/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1- find the starting point of diagonal and do i++,j-- ;
*/


vector<vector<int> > Solution::diagonal(vector<vector<int> > &a) {
    int n= a.size();
    
    vector<vector<int>>res;
    vector<int>temp;
    for(int k=0;k<n;k++)
    {
        temp.clear();
        int i= 0,j=k;
        while(j>=0)
        {
            temp.push_back(a[i][j]);
            j--;i++;
        }
        res.push_back(temp);
    }
    
    for(int k= 1;k<n;k++)
    {
        int i= k,j=n-1;
        temp.clear();
        while(j>=k)
        {
            temp.push_back(a[i][j]);
            j--;i++;
        }
        res.push_back(temp);      
    }    
    return res;
}
