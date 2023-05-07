/*
    name= min cost path
    link- https://www.interviewbit.com/problems/min-cost-path/
    author- Parth garg
    time complexity- n*m(log(n*m))
    space complexity- o(n*m)
    method 1- dijkstra;
*/

#define ll long long
#define pp pair< int , pair< int , int >>
int Solution::solve(int A, int B, vector<string> &grid) {
    vector<vector<long long>>dist(A,vector<long long>(B,INT_MAX));
    priority_queue <pp, vector<pp>, greater<pp>> pq;
    //store (i,j) as x= 3i +j where i = x/3 and j= x%3; 
    int x= 0;
    
    int dx[4]={0 , 0 , -1 , 1}; // row
    int dy[4]={-1 , 1 , 0 , 0}; // col
    int left=0 , right=1 , top=2 , down=3;
    dist[0][0] = 0;
    pq.push({0 , {0 , 0}});
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        
        int cost=t.first;
        
        int i=t.second.first;
        int j=t.second.second;
          
        char ch=grid[i][j];
        int index;
         
        if(ch=='L')
        {
            index=left;
        }
        else if(ch=='R')
        {
            index=right;
        }
        else if(ch=='U')
        {
            index=top;
        }
        else{
            index=down;
        }
        
        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dy[k];
            
            if(newi>=0 && newj>=0 && newi<A && newj<B){
                if(k==index)
                {
                    if(dist[newi][newj]>cost)
                    {
                        dist[newi][newj]=cost;
                        pq.push({cost , {newi , newj}});
                    }
                }
                else{
                    if(dist[newi][newj]>cost+1)
                    {
                        dist[newi][newj]=cost+1;
                        pq.push({1+cost , {newi , newj}});
                    }
                }
            } 
            
        }
        
    }
    if(dist[A-1][B-1]==INT_MAX)
    {
        return -1;
    }
    
    return dist[A-1][B-1];
    
}
