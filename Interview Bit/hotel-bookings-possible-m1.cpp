/*
    name= hotel bookings possible
    link-  https://www.interviewbit.com/problems/hotel-bookings-possible/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity-  o(n)
    method 1;
*/


bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    priority_queue<int,vector<int>,greater<int>>p;  // store departure time in min heap
    vector<pair<int,int>>v;
    for(int i=0;i<arrive.size();i++)
    {
        v.push_back({arrive[i],depart[i]});
    }
    sort(v.begin(),v.end());
    
    int ans= 1;
    p.push(v[0].second);
    
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first <= p.top())
        {
            p.push(v[i].second);
        }
        else
        {
            while(!p.empty() && p.top() < v[i].first )
                p.pop();
            
            p.push(v[i].second);
        }
        if(p.size()>ans) ans= p.size();
    }
    
    if(K>= ans) return true;
    else return false;
    
}
