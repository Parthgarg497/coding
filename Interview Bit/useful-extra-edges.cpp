/*
    name= useful extra edges
    link- https://www.interviewbit.com/problems/useful-extra-edges/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(v+e)
    method 1- Use dijkstra 2 times. Once with C as origin and another
        with D as origin. Now for every node, you have the length of the shortest path from
        C and from D. Now you can just iterate over each road and check if this road
        helps you decreasing the existing distance between C and D.;
*/
const int INF = 1e9;
void findShortestPath(vector<vector<pair<int,int>>>&graph,int C, vector<int>&dist){
    int n= graph.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,C});
    
    dist[C] = 0;
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto child : graph[node]){
            int v= child.first;
            int w = child.second;
            if(dist[v] > w+ wt){
                dist[v] = wt+ w;
                pq.push({dist[v],v});
            }
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<pair<int,int>>>graph(A+1);
    
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back({B[i][1],B[i][2]});
        graph[B[i][1]].push_back({B[i][0],B[i][2]});
    }
    vector<int>dist1(A+1, INF);
    vector<int>dist2(A+1, INF);
    
    findShortestPath(graph,C,dist1);
    findShortestPath(graph,D,dist2);
    
    int ans= dist1[D];
    for(int i=0;i<E.size();i++){
        int u= E[i][0];
        int v= E[i][1];
        int w= E[i][2];
        
        ans= min(ans, min(dist1[u]+w+dist2[v] ,dist2[u]+w+dist1[v] ));
    }
    
    if(ans == INF){
        return -1;
    }
    else return ans;
    
}
