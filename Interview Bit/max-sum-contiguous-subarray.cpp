
/*
    name= Max Sum Contiguous Subarray
    link- https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::maxSubArray(const vector<int> &a) {
    int ans= INT_MIN; 
    int sum=0;
    int n= a.size();
    for(int i=0; i<n;i++)
    {
        sum+= a[i];
        ans= max(sum, ans);
        if(sum<0)
        {
            sum=0;
        }   
    }
    return ans;
    
}
