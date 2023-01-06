/*
    name= 3 sum
    link- https://www.interviewbit.com/problems/3-sum/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(1)
    method 1; 
*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size()<3){
        int sum=0;
        for(int i=0;i<A.size();i++)sum+= A[i];
        return sum;
    }
    int n= A.size();
    sort(A.begin(),A.end());
    int ans;
    int minDiff= INT_MAX;
    for(int i=0;i<=n-3;i++)
    {
        int l= i+1;
        int r= n-1;
        while(l<r)
        {
            int sum= A[i]+ A[l]+A[r];
            if( sum > B ) r--;
            else if(sum < B) l++;
            else {
                return B;
            }
            
            if(abs(B- sum) < minDiff){
                minDiff= abs(B-sum);
                ans= sum;
            }
        }
    }
    return ans;
    
}
