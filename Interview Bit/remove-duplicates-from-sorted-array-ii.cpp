/*
    name= Remove Duplicates from Sorted Array II
    link- https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/


int Solution::removeDuplicates(vector<int> &A) {
    
    int i,j;
    if(A[0]==A[1]) i=2;
    else i=1;
    j= i;
    
    while(j<A.size()){
        if(A[j]== A[j-1])j++;
        else{
            if( j+1 < A.size() && A[j+1] == A[j]){
                A[i]= A[j];
                A[i+1]= A[j+1];
                i+=2;
                j+=2;
            }
            else{
                A[i]= A[j];
                i++;j++;
            }
        }
    }
    while(i!= A.size()) A.pop_back();
    return i;
    
}
