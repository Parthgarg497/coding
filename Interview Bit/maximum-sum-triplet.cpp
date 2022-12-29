
/*
    name= maximum sum triplet
    link-
    author- Parth garg
    time complexity- o(nlogn) 
    space complexity- o(2n) 
    method 1- fix middle element and for left element use binary search
     in left sorted part and find right element by precomputation;
*/


int Solution::solve(vector<int>&arr) {
    int n= arr.size();
    int maxi[n];
    maxi[n-1]= arr[n-1];
    
    for(int i= n-2; i>=0;i--)
    {
        if(arr[i] > maxi[i+1]) maxi[i]= arr[i];
        else maxi[i]= maxi[i+1];
    }
    
    set<int>s;
    s.insert(arr[0]);
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
        auto it= s.lower_bound(arr[i]);
        if(*(it) == *(s.begin()) || arr[i] >= maxi[i+1]) 
        {
            s.insert(arr[i]);
            continue;
        }
        else
        {
            it--;
        }
        
        ans= max(ans, *(it) + arr[i]+ maxi[i+1]);
        s.insert(arr[i]);
           
    }
    
    return ans;        

}
