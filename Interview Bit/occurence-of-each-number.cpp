/*
    name= occurence of each number
    link- https://www.interviewbit.com/problems/occurence-of-each-number/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1;
*/

vector<int> Solution::findOccurences(vector<int> &a) {
    map<int,int>m;
    for(int i=0;i<a.size();i++)
    {
        m[a[i]]++;
    }
    vector<int>res;
    for(auto it= m.begin();it!= m.end();it++)
    {
        res.push_back(it->second);
    }
    return res;
}
