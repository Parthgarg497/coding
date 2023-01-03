/*
    name=  max distance
    link-  https://www.interviewbit.com/problems/max-distance/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1;
*/


int Solution::maximumGap(const vector<int> &A) {
    int n= A.size();
    int ans= 0;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({A[i],i});
    }
    sort(v.begin(),v.end());
    
    vector<int>suffixMax(n);
    suffixMax[n-1]= v[n-1].second;
    
    for(int i= n-2;i>=0;i--)
    {
        suffixMax[i]= max(suffixMax[i+1], v[i].second);
    }
    
    for(int k=0;k<n;k++)
    {
        int i= v[k].second;
        int j= suffixMax[k];
        
        if(j>=i) ans= max(ans, j-i);
        
    }
    
    return ans;
    
}
