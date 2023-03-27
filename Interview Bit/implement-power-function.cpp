/*
    name= implement power function 
    link- https://www.interviewbit.com/problems/implement-power-function/
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(logn) ->stack
    method 1;
*/

int Solution::pow(int x, int n, int m) {
    if(x==0) return 0;
    if(n==0) return 1;
    int k= pow(x,n/2,m);
    if(n&1){
        return (((((k*1LL*k)%m)*(x%m))%m) +m)%m;
    }
    else{
        return (((k*1LL*k)%m)+m)%m;
    }
}
