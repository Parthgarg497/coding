/*
    name=  total-moves-for-bishop
    link- https://www.interviewbit.com/problems/total-moves-for-bishop/
    author- Parth garg
    time complexity-  o(1)
    space complexity- o(1)
    method 1;
*/


int Solution::solve(int i, int j) {
    int up= i-1;
    int down= 8-i;
    int left= j-1;
    int right= 8-j;
    
    return min(up,left)+min(up,right)+min(down,left)+min(down,right);
}
