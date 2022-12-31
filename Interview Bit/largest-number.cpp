/*
    name= largest number
    link- https://www.interviewbit.com/problems/largest-number/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1- use comparator function while sorting;
*/


bool comp(string a, string b)
{
    return a+b > b+a;
}

string Solution::largestNumber(const vector<int> &A) {
    int n= A.size();
    
    vector<string>v;
    for(int i=0;i<n;i++)
    {
        v.push_back(to_string(A[i]));
    }
    sort(v.begin(),v.end(),comp);
    string res;
    for(int i=0;i<n;i++)res+= v[i];
    
    int idx=0;
    while(res[idx]== '0' && idx+1 < res.size()) idx++;

    return  res.substr(idx);
    
}
