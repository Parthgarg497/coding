
/*
    name= array 3 pointers
    link- https://www.interviewbit.com/problems/array-3-pointers/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int na= A.size();
    int nb= B.size();
    int nc= C.size();
    int i=0,j=0,k=0;
    int minOfMax= INT_MAX;
    
    while(i<na && j<nb && k<nc)
    {
        int mn= min(min(A[i],B[j]) , C[k]);
        int mx= max(max(A[i],B[j]) , C[k]);
        minOfMax= min(minOfMax, mx-mn);
        // cout<<A[i]<<" "<<B[j]<<" "<<C[k]<<endl;
        
        if(A[i]<= B[j] && A[i] <= C[k] ) i++;
        else if(B[j]<= A[i] && B[j]<= C[k]) j++;
        else k++;
        
    }
    return minOfMax;
}
