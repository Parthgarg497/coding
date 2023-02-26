/*
    name= smaller or equal elements
    link- https://www.interviewbit.com/problems/smaller-or-equal-elements/
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(1)
    method 1;
*/

int Solution::solve(vector<int> &A, int B) {
    int n= A.size();
    int l=0;
    int r= n-1;
    int mid= 0;
    while(l<r){
        mid= l+ (r-l)/2;
        if(A[mid] <= B){
            l= mid+1;
        }
        else if(A[mid]> B){
            r= mid;
        }
    }
    if(A[l]<= B ){
        return l+1;
    } 
    else return l;
}
