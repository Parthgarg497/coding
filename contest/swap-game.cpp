/*
    name= swap game
    link- https://codeforces.com/contest/1747/problem/C
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
        int arr[n];
        fori(i,n)cin>>arr[i];
        int minElement= INT_MAX;
        int idx;
        fori(i,n)
        {
            if(arr[i]<minElement)
            {
                minElement= arr[i];
                idx= i;
            }
        }
        if(idx==0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}