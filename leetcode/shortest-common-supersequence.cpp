
/*
    name= shortest common supersequence
    link- https://leetcode.com/problems/shortest-common-supersequence/submissions/
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- take help of longest common subsequence;
*/




class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m= str1.length();
        int n= str2.length();
        vector<vector<string>>dp(m+1,vector<string>(n+1,""));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(str1[i]== str2[j])
                    dp[i+1][j+1]= dp[i][j]+str1[i];
                else
                    dp[i+1][j+1]= (dp[i][j+1].length()>dp[i+1][j].length()) ? dp[i][j+1] : dp[i+1][j];
            }
        }
        
        string result;
        int i=0,j=0;
        for(auto c: dp[m][n])
        {
            while(str1[i]!= c)
                result.push_back(str1[i++]);
            while(str2[j]!= c)
                result.push_back(str2[j++]);
            
            result.push_back(c);
            i++;j++;
        }
        while(i!= m)
        {
            result.push_back(str1[i]);
            i++;
        }
        while(j!= n)
        {
            result.push_back(str2[j]);
            j++;
        }
        return result;
    }
};