/*
    name= remove element from array
    link- https://www.interviewbit.com/problems/remove-element-from-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::removeElement(vector<int> &A, int B) {
    int i=0,j;
    int n= A.size();
    while(i<n && A[i]!= B)i++;
    j=i;
    
    while(j<n){
        if(A[j]!= B){
            swap(A[i],A[j]);
            i++;
        }
        j++;
    }
    
    return i;
}
