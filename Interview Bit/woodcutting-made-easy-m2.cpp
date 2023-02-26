/*
    name= woodcutting made easy
    link- https://www.interviewbit.com/problems/woodcutting-made-easy/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 2;
*/

int findIndex(vector<int>&A, int x){
    int n= A.size();
    int l=0,r= n-1;
    
    while(l<=r){
        int mid= l+ (r-l+1)/2;
        if(A[mid]> x) {
            r=mid-1;
        }
        else{
            l= mid+1;
        }
    }
    return r;
}

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n= A.size();
    
    vector<long long>prefixSum(n);
    prefixSum[0]= A[0];
    for(int i=1;i<n;i++){
        prefixSum[i]= prefixSum[i-1]+ A[i];
    }
    
    int l= 0,r= A[n-1];
    while(l<=r){
        int mid= l+ (r-l+1)/2;
        int idx= findIndex(A, mid);
        long long sum;
        if(idx==-1){
            sum= prefixSum[n-1]- (n* mid);
        }
        else{
            sum= prefixSum[n-1]- prefixSum[idx] - (mid*(n-(idx+1)));
        }
        
        if(sum > B){
            l= mid+1;
        }
        else if(sum < B){
            r= mid-1;
        }
        else{
            return mid;
        }
    }
    
    return r;
}
    