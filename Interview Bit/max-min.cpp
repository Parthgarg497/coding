
/*
    name= max-min
    link- https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/?utm_medium=referral&utm_source=https://www.interviewbit.com/practice/
    author- Parth garg
    time complexity- o(n) - comparisons(~ 3n/2)
    space complexity- o(1)
    method 1- break the array in 2 partitions and compare the ans between those 2 recursively;
*/



pair<int,int> partition(vector<int>&a, int start, int end)
{
    if(start== end)
    {
        return {a[start],a[end]};
    }
    
    int mid= (start+end)/2;
    pair<int,int> p1= partition(a,start,mid);
    pair<int,int> p2= partition(a,mid+1,end);
    
    return {max(p1.first,p2.first), min(p1.second,p2.second)};
}

int Solution::solve(vector<int> &a) {
    pair<int,int>maxMin= partition(a,0,a.size()-1);
    return (maxMin.first)+(maxMin.second);
}
