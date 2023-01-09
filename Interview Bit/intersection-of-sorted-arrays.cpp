/*
    name= intersection of sorted arrays
    link- https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
    author- Parth garg
    time complexity- o(n+m) in worst case
    space complexity- o(min(n,m)) - in worst case
    method 1;
*/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int>res;
    int i=0,j=0;
    int n= A.size();
    int m= B.size();
    while(i<n && j<m){
        if(A[i]== B[j]){
            res.push_back(A[i]);
            i++;j++;
        }
        else if(A[i]>B[j])j++;
        else i++;
    }
    return res;
}
