/*
    name= prime sum
    link- https://www.interviewbit.com/problems/prime-sum/
    author- Parth garg
    time complexity- n*sqrt(n)
    space complexity- o(1)
    method 1;
*/

bool isprime(int n)
{
    if(n==0 || n==1) return false;
    
    for(int i=2;i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

vector<int> Solution::primesum(int n) {

    vector<int>res(2);
    for(int i=2;i<=n/2;i++)
    {
        if(!isprime(i))continue;
        if(!isprime(n-i))continue;
        else{
            res[0]=i;
            res[1]=n-i;
            break;
        }
    }
    return res;
}
