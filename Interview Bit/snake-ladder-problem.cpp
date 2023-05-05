/*
    name= snake ladder problem
    link- https://www.interviewbit.com/problems/snake-ladder-problem/
    author- Parth garg
    time complexity- o(100)
    space complexity- o(100)
    method 1- dp;
*/

int solve( vector<int>&dp, int i,unordered_map<int,int>&ladder,unordered_map<int,int>&snake){
    if(i== 100) return 0;
    if(dp[i] != -1) return dp[i];
    
    if(ladder[i] != 0 ) return dp[i] = solve(dp,ladder[i], ladder,snake);
    if(snake[i] != 0) {
        dp[i] = 10000;
        return solve(dp,snake[i],ladder,snake)-1;
    }
    
    int ans= 10000;
    for(int k= 1; k<7;k++){
        if(i+k<=100)
            ans= min(ans, 1+solve(dp,i+k,ladder,snake));
    }

    return dp[i] = ans;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int>dp(101,-1);
    unordered_map<int,int>ladder,snake;
    for(int i=0;i<A.size();i++){
        ladder[A[i][0]]= A[i][1]; 
    }
    for(int i=0;i<B.size();i++){
        snake[B[i][0]]= B[i][1]; 
    }
    int ans=solve(dp,1,ladder,snake); 

    return ans>=10000 ?-1 : ans ;
    
}
