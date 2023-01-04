
/*
    name=  Distribute in Circle!
    link-  https://www.interviewbit.com/problems/distribute-in-circle/
    author- Parth garg
    time complexity- o(1)
    space complexity- o(1)
    method 1;
*/


int Solution::solve(int A, int B, int C) {
    int x= A%B;
    return (C+x-1)%B;
}
