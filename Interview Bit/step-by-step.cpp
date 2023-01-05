
/*
    name= step by step
    link- https://www.interviewbit.com/problems/step-by-step/
    author- Parth garg
    time complexity- o(moves)
    space complexity- o(1)
    method 1;
*/
int Solution::solve(int A) {
    A= abs(A);
    long long int x=0,i=1;
    while(x<A)x+=i++;
    if(x==A||(x-A)%2==0)return i-1;
    if(i%2==0){
        return i-1+2;
    }
    return i-1+1;
}
