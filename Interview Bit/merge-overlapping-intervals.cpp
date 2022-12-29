/*
    name= merge overlapping intervals
    link- https://www.interviewbit.com/problems/merge-overlapping-intervals/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1; 
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp(Interval i1,Interval i2)
{
    return i1.start<i2.start;
}
 
vector<Interval> Solution::merge(vector<Interval> &a) {
    if(a.size()<=1) return a;
    
    int n= a.size();
    vector<Interval>result;
    sort(a.begin(),a.end(),comp);
    Interval newInterval;
    Interval currInterval= a[0];
    for(int i=0;i<n-1;i++)
    {
        newInterval= a[i+1];
        if(newInterval.start <= currInterval.end)
        {
            currInterval.end= max(currInterval.end, newInterval.end);
        }
        else
        {
            result.push_back(currInterval);
            currInterval= newInterval;
        }
    }
    result.push_back(currInterval);
    return result;
}
