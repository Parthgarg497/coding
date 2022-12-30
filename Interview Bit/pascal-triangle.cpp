
/*
    name= pascal triangle
    link- https://www.interviewbit.com/problems/pascal-triangle/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1;
*/

vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int>>result;
    if(A==0) return result;
    
    result.push_back({1});
    if(A==1) return result;
    
    vector<int>temp;
    for(int i=1;i<A;i++)
    {
        temp.clear();
        int c= 1;
        for(int j=1;j<=i+1;j++)
        {
            temp.push_back(c);
            c= c*(i+1-j)/j ;
        }
        result.push_back(temp);
    }
    return result;
}
