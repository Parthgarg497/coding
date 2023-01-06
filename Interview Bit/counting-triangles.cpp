/*
    name= counting triangles
    link- https://www.interviewbit.com/problems/counting-triangles/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(1)
    method 1;
*/


int Solution::nTriang(vector<int> &A) {
    if(A.size()<3){
        return 0;
    }
    int m= 1e9+7;
    int n= A.size();
    sort(A.begin(),A.end());
    int ans=0;
    
    for(int i= n-1;i>=2;i--)
    {
        int l= 0,r=i-1;
        while(l<r)
        {
            if(A[l]+A[r] > A[i]) {
                ans= (ans + (r-l))%m ; 
                r--;
            }
            else l++;
        }
    }
    
    return ans%m;
}
