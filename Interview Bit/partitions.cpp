/*
    name= partitions
    link- https://www.interviewbit.com/problems/partitions/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/


int Solution::solve(int n, vector<int> &a) {
    
    vector<int>prefix(n);
    vector<int>counter(n);
    prefix[0]= a[0];
    
    for(int i=1;i<n;i++)
    {
        prefix[i]= prefix[i-1]+a[i];
    }
    
    if(prefix[n-1]%3 != 0) return 0;
    else
    {
        int num1= prefix[n-1]/3;
        int num2= (2*prefix[n-1])/3;
        counter[n-1]=0;
        int ans=0;
        for(int i= n-2;i>=0;i--)
        {
            if(prefix[i]== num2 ) counter[i]= counter[i+1]+1;
            else counter[i]= counter[i+1];
        }
        
        for(int i=0;i<n-2;i++)
        {
            if(prefix[i]== num1) 
            {
                ans+= counter[i+1];
            }
        }
        return ans;
    }
}
