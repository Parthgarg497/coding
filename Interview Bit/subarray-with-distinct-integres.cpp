/*
    name= subarrays-with-distinct-integers
    link- https://www.interviewbit.com/problems/subarrays-with-distinct-integers/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

int atmostk(vector<int>&A, int k)
{
    int n= A.size();
    unordered_map<int,int>m;
    int i=0,j=0,ans=0;
    while(j<n)
    {
        m[A[j]]++;
        while(m.size()>k){
            m[A[i]]--;
            if(m[A[i]]==0) m.erase(A[i]);
            i++;
        }
        ans+= (j-i+1);
        j++;
    }
    return ans;
}
int Solution::solve(vector<int> &A, int B) {
    return atmostk(A,B)- atmostk(A,B-1);
}
