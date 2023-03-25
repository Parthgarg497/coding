/*
    name= sorted insert position 
    link- https://www.interviewbit.com/problems/sorted-insert-position/
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(1)
    method 1;
*/

int Solution::searchInsert(vector<int> &A, int B) {
    int l= 0,r= A.size()-1;
    if(B > A.back()) return A.size();
    else if(B< A[0]) return 0;
    while(l<r){
        int mid = l+ (r-l)/2;
        if(A[mid] <B){
            l= mid+1;
        }
        else{
            r= mid;
        }
    }
    return l;
}
