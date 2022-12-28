
/*
    name=merge intervals
    link- https://www.interviewbit.com/problems/merge-intervals/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n) for storing result
    method 1 - take all the edges cases and cases of overlaping ;
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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int n= intervals.size();
    vector<Interval>result;
    if(n==0)
    {
        result.push_back(newInterval);
        return result;
    }
    if(newInterval.end < intervals[0].start ) 
    {
        result.push_back(newInterval);
        for(int i=0;i<n;i++)result.push_back(intervals[i]);
        return result;
    }
    
    
    int i;
    for(i=0;i<n;i++)
    {
        if(intervals[i].end < newInterval.start)
        {
            result.push_back(intervals[i]);
        }
        else
        {
            break;
        }
    }
    if(i==n)
    {
        result.push_back(newInterval);
        return result;
    }
    
    Interval updatedInterval;
    updatedInterval.start= min(intervals[i].start, newInterval.start);
    if(newInterval.end < intervals[i].start)
    {
        updatedInterval.end=  newInterval.end;
    }
    else
    {
        updatedInterval.end= max(newInterval.end, intervals[i].end);
        i++;
        while(i < n)
        {
            if(intervals[i].start < updatedInterval.end)
            {
                updatedInterval.end= max(intervals[i].end, updatedInterval.end);
                i++;
            }
            else break;
        }
    }
    
    result.push_back(updatedInterval);
    while(i<n) 
    {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
    
}
