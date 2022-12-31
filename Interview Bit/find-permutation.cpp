/*
    name= find permutation
    link- https://www.interviewbit.com/problems/find-permutation/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

vector<int> Solution::findPerm(const string A, int B) {
    int n= A.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]== 'D')count++;
    }
    count++;
    int num=count-1;
    
    vector<int>res;
    res.push_back(count);
    count++;
    for(int i=0;i<n;i++)
    {
        if(A[i]== 'I') res.push_back(count++);
        else res.push_back(num--);
    }
    return res;
    
}
