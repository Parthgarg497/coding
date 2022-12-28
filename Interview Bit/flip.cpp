/*
    name= flip
    link- https://www.interviewbit.com/problems/flip/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)   we can also do this without making extra array for storing -1's and 1's
    method 1- extension of kadane's algorithm;
*/


vector<int> Solution::flip(string s) {
    int n= s.length();
    vector<int>v(n);
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') v[i]=-1;
        else v[i]= 1;
    }
    
    int l=0;
    int maxAns=0;
    int sum=0;
    vector<int>result(2);
    result[0]= -1;
    result[1]= -1;
    for(int i=0;i<n;i++)
    {
        sum+= v[i];
        if(sum>maxAns)
        {
            maxAns= sum;
            result[0]=l+1;
            result[1]= i+1;   // +1 because of 1 based indexing 
        }
        if(sum<0)
        {
            l= i+1;
            sum=0;
        }
    }
    if(result[0]== -1) 
    {
        result.pop_back();
        result.pop_back();
        return result;
    }
    else return result;

}
