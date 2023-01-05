
/*
    name= power of two integres
    link- https://www.interviewbit.com/problems/power-of-two-integers/
    author- Parth garg
    time complexity- o(sqrt(n)log(n))
    space complexity- o(1)
    method 1;
*/

int Solution::isPower(int n) {
    for(int i=1; i*i<=n;i++)
    {
        int p= log(n)/log(i);
        if(pow(i,p)==n) return 1;
    }
    return 0;
}
