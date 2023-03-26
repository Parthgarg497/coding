/*
    name= Capacity To Ship Packages Within B Days
    link- https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/
    author- Parth garg
    time complexity- o(n*log(sum))
    space complexity- o(1)
    method 1;
*/

bool check(vector<int>&A ,int B, int capacity){
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

int Solution::solve(vector<int> &A, int B) {
    
    int l=1,r=0;
    for(int i=0;i<A.size();i++){
        r+= A[i];
    }
    
    while(l<r){
        int mid = l+ (r-l)/2;
        if(check(A,B,mid)){
            r= mid;
        }
        else{
            l= mid+1;
        }
    }
    return l;
    
}
