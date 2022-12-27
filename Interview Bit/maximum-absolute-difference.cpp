/*
    name= maximum absolute difference
    link- https://www.interviewbit.com/problems/maximum-absolute-difference/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- suppose j>i  and then we have 2 cases Ai>Aj or Aj>Ai  
            open the mod and find the equation for both the case ;
*/

int Solution::maxArr(vector<int> &a) {
    int n= a.size();
    int ans= 0;
    int maxi1= INT_MIN;
    int maxi2= INT_MIN;
    int mini1= INT_MAX;
    int mini2= INT_MAX;
    
    
    for(int i=0;i<n;i++)
    {   
        maxi1= max(maxi1, a[i]+i);
        mini1= min(mini1, a[i]+i);
        maxi2= max(maxi2, a[i]-i);
        mini2= min(mini2, a[i]-i);       
    }
    ans= max(maxi1-mini1, ans);
    ans= max(ans, maxi2-mini2);
    return ans;
}


