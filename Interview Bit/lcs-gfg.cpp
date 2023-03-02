/*
    name= Longest Common Subsequence
    link- https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1;
*/

class Solution
{
    public:
    int maxLength(int i, int j , vector<vector<int>>&dp, string &s1, string &s2){
        if(i>= s1.length() || j>= s2.length()) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(s1[i]== s2[j]) {
            return dp[i][j]= 1+ maxLength(i+1,j+1, dp, s1,s2);
        }
        else{
            return dp[i][j]= max(maxLength(i+1,j, dp, s1,s2),maxLength(i,j+1, dp, s1,s2));
        }
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x, vector<int>(y,-1));
        return maxLength(0,0,dp,s1,s2);
    }
};