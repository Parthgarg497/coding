/*
    name= wave array
    link-  https://www.interviewbit.com/problems/wave-array/
    author- Parth garg
    time complexity- o(nlogn) 
    space complexity- o(1)
    method 1;
*/

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i= i+2)
    {
        if(i== A.size()-1)break;
        
        swap(A[i],A[i+1]);
    }
    return A;
}
