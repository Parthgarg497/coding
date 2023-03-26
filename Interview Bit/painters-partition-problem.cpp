/*
    name= painter's partition problem 
    link- https://www.interviewbit.com/problems/painters-partition-problem/
    author- Parth garg
    time complexity- o(n log(sum))
    space complexity- o(1)
    method 1;
*/

bool check(vector<int>&A ,int B ,int capacity){
    int sum =0;
    for(int i=0;i<A.size();i++){
        if(A[i] > capacity){
            return false;
        }
        if((sum+A[i]) <=capacity){
            sum+= A[i];
        }
        else{
            B--;
            sum = A[i];
        }
    }
    if(B >=1 ) return true;
    else return false;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long l= 1,r=0;
    const int m= 10000003;
    for(int i=0;i<C.size();i++)r+= C[i];
    
    while(l<r){
        long long mid= l+ (r-l)/2;
        if(check(C,A,mid)){
            r= mid;
        }
        else{
            l= mid+1;
        }
    }
    int ans= ((l%m)*1LL*(B%m))%m;
    return ans;
}
