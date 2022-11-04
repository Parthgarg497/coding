/*
    name= two groups
    link-  https://codeforces.com/contest/1747/problem/A
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
 
        int posSum=0,negSum=0;
        fori(i,n)
        {
            if(arr[i]<0)negSum+= arr[i];
            else posSum+= arr[i];
        }
        cout<<abs(abs(posSum)-abs(negSum))<<endl;
 
    }
}