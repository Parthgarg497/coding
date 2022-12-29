/*
    name= make equal elements array
    link- https://www.interviewbit.com/problems/make-equal-elements-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1; 
*/


bool check(vector<int>&a, int x,int y)
{
    for(auto i:a)
    {
        if(i-x==y || i+x==y || i==y) {}
        else return 0;
    }
    return true;
}

int Solution::solve(vector<int> &a, int x) {
    int n= a.size();
    if(check(a,x,a[0]) || check(a,x,a[0]-x) || check(a,x,a[0]+x)) return 1;
    else return 0;
}
