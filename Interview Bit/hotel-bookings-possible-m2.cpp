/*
    name= hotel bookings possible
    link-  https://www.interviewbit.com/problems/hotel-bookings-possible/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity-  o(n)
    method 1;
*/



bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n= arrive.size();
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({arrive[i],0});
        v.push_back({depart[i],1});
    }
    sort(v.begin(),v.end());
    
    int currActive= 0;
    int ans=0;
    for(int i=0;i< v.size();i++)
    {
        if(v[i].second== 0) 
        {
            currActive++;
            ans= max(ans, currActive);
        }
        else
        {
            currActive--;
        }
    }
    if(ans<= K) return true;
    else return false;
    
}
