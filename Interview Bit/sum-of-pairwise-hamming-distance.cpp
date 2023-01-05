
/*
    name= sum of pairwise hamming distance
    link- https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::hammingDistance(const vector<int> &A) {
    const int m= 1e9+7;
    if(A.size()==1)return 0;
    int n= A.size();
    int ans=0;
    for(int i=0;i<31;i++)
    {
        int ones=0,zeros=0;
        for(int j=0;j<n;j++)
        {
            if(A[j] & (1<<i)) ones++;
            else zeros++; 
        }
        ans= ans+ ((2LL * ones *zeros)%m);
        ans= ans%m;
    }
    return ans;
}
