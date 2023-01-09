/*
    name= remove duplicates from sorted array
    link- https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

int Solution::removeDuplicates(vector<int> &A) {
    
    int i=1,j=1;
    while(j<A.size()){
        
        if(A[j]!= A[j-1]){
            A[i]= A[j];
            i++;
        }
        j++;
    }
    while(i!= A.size()){
        A.pop_back();
    }
    return i;
}
