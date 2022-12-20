/*
    name= absolute sorting
    link- https://codeforces.com/contest/1772/problem/D
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- take pair of two consecutive and find the range of x by which the condition is 
    satisfying and then take the intersection of all values of x for all pairs;
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i, n) for (int32_t i = 0; i < int32_t(n); i++)

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    fori(i,n)
    cin>>arr[i];

    int mn=0,mx= 1e9;
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]> arr[i+1])
        {
            mn= max(mn, (arr[i]+arr[i+1]+1)/2);
            
        }
        else if(arr[i]< arr[i+1])
        {
            mx= min(mx,(arr[i]+arr[i+1])/2);
        }
    }
    if(mx>= mn) 
    {
        cout<<mx<<endl;
    }
    else
    {
        cout<<-1<<endl; 
    }
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}