/*
    name= binod
    link- https://www.codechef.com/START65C/problems/BIN_OD
    author- Parth garg
    time complexity- o(60*n)
    space complexity- o(60*n)
    method 1- store the prefix sum of no. of 1's occured at jth position in binary string of any element;
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
        int n,q;
        cin>>n>>q;
        int arr[n];
        fori(i,n)cin>>arr[i];

        //prefixBinarySum[i][j] represents no. of 1's occured up to ith element in array from 1st element 
        // and j maps with k 
        vector<vector<int>>prefixBinarySum(n+1,vector<int>(60,0));


        for(int j=0;j<60;j++)
        {
            for(int i=1;i<=n;i++)
            {
                prefixBinarySum[i][j]= prefixBinarySum[i-1][j]+ (arr[i-1]%2);
                arr[i-1]/=2;
            }
        }


        while(q--)
        {
            int k,l1,r1,l2,r2;
            cin>>k>>l1>>r1>>l2>>r2;

            // no. of 1s in range l1 to r1 at kth position and same for l2 to r2
            int l1r1= prefixBinarySum[r1][k]-prefixBinarySum[l1-1][k];
            int l2r2= prefixBinarySum[r2][k]-prefixBinarySum[l2-1][k];

            int ans = (l1r1*(r2-l2+1- l2r2) )+ (l2r2* (r1-l1+1- l1r1));
            cout<<ans<<endl;
        }
        
    }
}