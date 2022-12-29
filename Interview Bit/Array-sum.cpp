/*
    name= array sum
    link- https://www.interviewbit.com/problems/array-sum/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    if(A.size()<B.size()) return addArrays(B,A);
    
    vector<int>result;
    int n= A.size()-1;
    int m= B.size()-1;
    int carry=0;
    while(m>=0)
    {
        int sum= carry+ A[n]+B[m];
        result.push_back(sum%10);
        carry= sum/10;
        n--;m--;
    } 
    while(n>=0)
    {
        int sum= carry + A[n];
        result.push_back(sum%10);
        carry= sum/10;
        n--;
    }
    if(carry!=0)
    result.push_back(carry);
    
    reverse(result.begin(),result.end());
    return result;
    
}
