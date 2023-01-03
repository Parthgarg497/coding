/*
    name=  Maximum Unsorted Subarray
    link-  https://www.interviewbit.com/problems/maximum-unsorted-subarray/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/


vector<int> Solution::subUnsort(vector<int> &A) {
    
    int n= A.size();

    int prefixMax = A[0], suffixMin = A[n-1];
    
    int l=n-1,r=0;
    int left_index=-1, right_index=-1;
    
    while(l>=0)
    {
        suffixMin = min(suffixMin, A[l]);
        if(suffixMin >= A[l] ){
            if(left_index==-1) left_index = l;
        }
        else{
            left_index = -1;
        }
        l--;
    }
    
    while(r<n)
    {
        prefixMax= max(prefixMax, A[r]);
        if(prefixMax  <= A[r])
        {
            if(right_index == -1) right_index= r;
        }
        else{
            right_index= -1;
        }
        r++;
    }
    if(right_index== -1) right_index= n;
    
    vector<int>res;
    if(left_index+1 > right_index-1)
    {
        res.push_back(-1);
        return res;
    }
    else{
        res.push_back(left_index+1);
        res.push_back(right_index-1);
        return res;
    }
    
}
