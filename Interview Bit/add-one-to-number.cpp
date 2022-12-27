
/*
    name= Add One To Number
    link- https://www.interviewbit.com/problems/add-one-to-number/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/


vector<int> Solution::plusOne(vector<int> &a) {
    int n= a.size();
    int carry=1;
    
    if(a[0]==0)
    {
        int i;
        for(i=0;a[i]==0;)
           i++;
        
        int j=0;
        while(i!=n)
        {
            a[j++]= a[i++];
        }
        j= n-j;
        while(j--) a.pop_back();
    }
    n= a.size();
    for(int i=n-1;i>=0;i--)
    {
        int sum= a[i]+carry;
        carry= sum/10;
        a[i] = sum%10;
        if(carry==0)break;
    }
    if(carry!=0)
    {
        a.push_back(carry);
        for(int i=n-1;i>=0;i--)
        {
            swap(a[i],a[i+1]);
        }
    }
    return a;
}
