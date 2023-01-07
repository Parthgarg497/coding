/*
    name= max consecutive series of 1s
    link- https://www.interviewbit.com/problems/max-continuous-series-of-1s/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1; 
*/


vector<int> Solution::maxone(vector<int> &A, int k) {
    int i=0,j=0;
    int n= A.size();
    int countZeros= A[0]==0 ? 1 : 0 ;
    int ans=min(k,n);
    int leftPtr=0,rightPtr= min(k-1,n-1);
    while(j<n && i<n)
    {
        while(j<n-1)
        {
            if(countZeros> k) break;
            j++;
            if(A[j]==0) countZeros++;
            if(j==n-1 && countZeros <=k){
                j++;
                break;
            }
        }
        if(j-i > ans){
            ans= j-i;
            leftPtr=i;
            rightPtr= j-1;
        }
        i++;
        if(i<n && A[i-1] == 0) countZeros--;
    }
    vector<int>res;
    while(leftPtr<=rightPtr){
        res.push_back(leftPtr);
        leftPtr++;
    }
    return res;
    
}
