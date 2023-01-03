/* 
    name=  repeat and missing number array
    link- https://www.interviewbit.com/problems/repeat-and-missing-number-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n= A.size();
    int diff=0;  //--- diff= b-a 
    for(int i=0;i<n;i++)
    {
        diff+= (i+1 -A[i]);        
    }
    
    long long sqDiff=0;
    for(int i=0;i<n;i++)
    {
        sqDiff+= (((i+1)*1LL*(i+1))-(A[i]*1LL*A[i]));
    }
    
    int b= ((sqDiff/diff)+diff)/2;
    int a= b-diff;
    
    vector<int>res;
    res.push_back(a);
    res.push_back(b);
    return res;  

}