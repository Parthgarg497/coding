
/*
    name= merge two sorted lists ii
    link- https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
    author- Parth garg
    time complexity- o(n+m)
    space complexity- o(n+m)
    method 1;
*/

void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int>t;
    for(int i=0;i<A.size();i++)t.push_back(A[i]);
    
    A.clear();
    int i=0,j=0;
    while(i<t.size() && j< B.size()){
        if(t[i]<B[j]){
            A.push_back(t[i]);
            i++;
        }
        else{
            A.push_back(B[j]);
            j++;
        }
    }
    while(i<t.size()){
        A.push_back(t[i]);
        i++;
    }
    while(j<B.size()){
        A.push_back(B[j]);
        j++;
    }
    
}
