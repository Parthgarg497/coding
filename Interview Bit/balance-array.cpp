/*
    name= balance array
    link- https://www.interviewbit.com/problems/balance-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/


int Solution::solve(vector<int> &A) {
    int n= A.size();
    vector<int>evenSum(n),oddSum(n);
    int count=0;
    evenSum[0]= A[0];
    oddSum[0]= 0;
    for(int i=1;i<n;i++)
    {
        if(i%2== 1)
        {
            evenSum[i]= evenSum[i-1];
            oddSum[i]= A[i]+oddSum[i-1];
        }
        else
        {
            evenSum[i]= A[i] + evenSum[i-1];
            oddSum[i]= oddSum[i-1];
        } 
    }
    
    for(int i=1;i<n-1;i++)
    {
        int even,odd;
        even= evenSum[i-1] + oddSum[n-1]-oddSum[i-1];
        odd= oddSum[i-1] + evenSum[n-1]-evenSum[i-1];
        
        if(i%2==0)
        {
            odd-= A[i];
        }
        else{
            even -= A[i];
        }
        if(even== odd){count= count+1;}
    }
    
    //i==0 case
    int even= oddSum[n-1];
    int odd= evenSum[n-1]-evenSum[0];
    if(even==odd) {count= count+1;}
    
    //i== n-1 case
    if(n-1 != 0)
    {
        even= evenSum[n-2];
        odd= oddSum[n-2];
        if(even== odd){ count= count+1;}
    }

    return count;
}
