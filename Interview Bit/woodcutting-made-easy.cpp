/*
    name= woodcutting made easy
    link- https://www.interviewbit.com/problems/woodcutting-made-easy/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

long long woodObtained(vector<int>&A, int x){
    long long s=0;
    int n= A.size();
    for(int i=0;i<n;i++){
        s+= max(0, A[i]-x);
    }
    return s;
}

int Solution::solve(vector<int> &A, int B) {
    int n= A.size();
    int l= 0,r= INT_MIN;
    for(int i=0;i<n;i++){
        r= max(A[i],r);
    }
    int mid;
    while(l<r){
        mid= l+ (r-l)/2;
        
        long long sum= woodObtained(A,mid);
        
        if(sum == B || l == mid) return mid; 
        if(sum > B){
            l= mid;
        }
        else if(sum < B){
            r= mid;
        }
    }
    
    return mid;

}


