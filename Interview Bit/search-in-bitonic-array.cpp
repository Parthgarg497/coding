/*
    name= search in bitonic array
    link- https://www.interviewbit.com/problems/search-in-bitonic-array/
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(1)
    method 1;
*/


int Solution::solve(vector<int> &A, int B) {
    int l=0;
    int n= A.size();
    int r= n-1;
    int br= 0;
    if(n==2){
        if(A[0]<A[1]){
            br= n+1;
        }
        else{
            br= 0;
        }
    }
    while(l<=r){
        int mid= l+ (r-l)/2;
        if(mid>0 && mid+1 < n && A[mid] > A[mid-1] && A[mid] > A[mid+1]){
            br= mid;
            break;
        }
        else if(mid>0 && mid+1 < n && A[mid] > A[mid-1] && A[mid] < A[mid+1]){
            l= mid+1;
        }
        else if(mid>0 && mid+1 < n && A[mid] < A[mid-1] && A[mid] > A[mid+1]){
            r= mid-1;
        }
        else{
            break;
        }
    }
    
    
    //checking first half
    int x=0,y=br;
    while(x<=y){
        int mid= x+ (y-x)/2;
        if(A[mid]> B){
            y= mid-1;
        }
        else if(A[mid]< B){
            x= mid+1;
        }
        else {
            return mid;
        }
    }
    
    //checking second half
    int m=br+1,p=n-1;
    while(m<=p){
        int mid= m+ (p-m)/2;
        if(A[mid]> B){
            m= mid+1;
        }
        else if(A[mid]< B){
            p= mid-1;
        }
        else {
            return mid;
        }
    }
    
    return -1;
    
}
