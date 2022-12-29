/*
    name= kth row of pascals triangle
    link-
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- find relation between two consecutive elements;
*/


vector<int> Solution::getRow(int n) {
    vector<int>res;
    int c=1;
    for(int i=1;i<=n+1;i++)
    {
        res.push_back(c);
        c= c*(n-i+1)/i;
    }
    return res;
}
