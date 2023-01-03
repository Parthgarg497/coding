/* 
    name= set matrix zero
    link- 
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(2n)
    method 1;
*/


void Solution::setZeroes(vector<vector<int> > &A) {
    set<int>rows;
    set<int>col;
    int n= A.size();
    int m= A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==0) 
            {
                rows.insert(i);
                col.insert(j);
            }
        }
    }
    
    for(auto i : rows)
    {
        for(int j=0;j<m;j++) A[i][j]=0;
    }
    
    
    for(auto j : col)
    {
        for(int i=0;i<n;i++) A[i][j]=0;
    }
    
}
