/*
    name= maximize the cut segments
    link- https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
    author- Parth garg
    time complexity- o(n)
    space complexity-  o(n)
    method 1;
*/


class Solution
{
    public:
    
    int findMaxSegments(int x,int y,int z, vector<int>&dp, int i){
        if(i ==0) return 0;
        if(i<0) return INT_MIN;
        
        if(dp[i]!= -1) return dp[i];
        int a= findMaxSegments(x,y,z,dp,i-x);
        int b= findMaxSegments(x,y,z,dp,i-y);
        int c= findMaxSegments(x,y,z,dp,i-z);
        
        return dp[i]= 1+ max(a,max(b,c));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        int ans= findMaxSegments(x,y,z,dp,n);
        return ans<0 ? 0 : ans;
    }
};