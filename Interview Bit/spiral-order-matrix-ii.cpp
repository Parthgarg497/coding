
/*
    name= spiral order matrix ii
    link- https://www.interviewbit.com/problems/spiral-order-matrix-ii/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1- fill the rings one by one;
*/

vector<vector<int> > Solution::generateMatrix(int n) {
    vector<vector<int>>res(n,vector<int>(n));
    
    int start=0,end= n-1;
    int x=1;
    for(start=0,end=n-1; start<=end; start++,end-- )
    {
        for(int i= start; i<=end;i++)   { res[start][i]=x; x++; }
        for(int i= start+1; i<=end;i++)  { res[i][end]=x; x++;   }
        for(int i= end-1; i>= start; i--) { res[end][i]=x; x++;   }
        for(int i= end-1; i>start; i--) { res[i][start]=x; x++; }
    }
    return res;
}
