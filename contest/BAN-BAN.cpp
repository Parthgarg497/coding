/*
    name= BAN BAN
    link-  https://codeforces.com/contest/1747/problem/B
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i, n) for (int32_t i = 0; i < int32_t(n); i++)
 
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2!=0)
        {
            cout<<1+ (n/2)<<endl;
            int i=0,j=(3*n)-1;
            while(i<j)
            {
                cout<<i+1<<" "<<j+1<<endl;
                i+=3;
                j-=3;
            }
        }
        else
        {
            cout<<n/2<<endl;
            int i=0,j= (3*n)-1;
            while(i<j)
            {
                cout<<i+1<<" "<<j+1<<endl;
                i+=3;
                j-=3;
            }
        }
    }
    
}