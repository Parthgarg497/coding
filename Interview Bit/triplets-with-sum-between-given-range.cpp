/*
    name= triplets-with-sum-between-given-range
    link-https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1;
*/

int Solution::solve(vector<string> &A) {    
    int n= A.size();
    vector<double>v(A.size());
    for(int i=0;i<n;i++)
    {
        v[i]= stod(A[i]);
    }
    
    sort(v.begin(),v.end());
    
    int i=-1,j=-1;
    
    for(int k=0;k<n;k++)
    {
        if(v[k] < (2.0/3))  { i=k; j=i; }
        else if(v[k]>= 2.0/3 && v[k] < 1 ) j=k;
    }    
    // AAA
    if(i>=2 &&( v[i]+v[i-1]+v[i-2])>1 && (v[i]+v[i-1]+v[i-2])<2) return 1;
    // AAB
    if(j>i && i>=1){
        float sum;
        int l=0,r=i;
        while(l<r)
        {
            sum= v[i+1]+v[l]+v[r];
            if(sum > 2) r--;
            else if(sum < 1) l++;
            else { return 1; }
        }
    }
    //ABB
    if(j>= i+2 && v[i+1]+v[i+2]+v[0] < 2 ) return 1;
    //AAC
    if( j+1<n && v[0]+v[1]+v[j+1] < 2) return 1;
    //ABC
    if( j+1<n && j>i && v[j+1] + v[i+1]+ v[0] <2 ) return 1;
    
    return 0;
    
    
}
