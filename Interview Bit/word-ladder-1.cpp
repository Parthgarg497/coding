/*
    name= word ladder 1
    link- https://www.interviewbit.com/problems/word-ladder-i/
    author- Parth garg
    time complexity- o(n*n*m) n= size of C , m = length of src string
    space complexity- o(n*m);
    method 1;
*/
const int INF = 1e9;
int Bfs(string &src ,string &dest, vector<string> &C){
    unordered_map<string, int> vis;
    int n= src.length();
    
    queue<string>q;
    q.push(src);
    vis[src] = 1;
    int ans=0;
    while(!q.empty()){        
        ans++;
        int sz = q.size(); 
        for(int z= 0;z<sz;z++){
            string top = q.front();
            q.pop();
            int d = 0; 
            for(int i=0;i<n;i++){
                if(dest[i] != top[i])d++;
            }
            if(d == 1){
                return ans+1;
            }
            
            for(int i= 0; i<C.size();i++){
                if(C[i].length() != n)continue;
                int count = 0;
                for(int j= 0;j<n;j++){
                    if(top[j] != C[i][j]) count++;
                }
                if(count == 1 && vis[C[i]] != 1){
                    q.push(C[i]);
                    vis[C[i]] = 1;
                }
            }
        }
    }
    return INF;
}

int Solution::solve(string A, string B, vector<string> &C) {
    int ans = Bfs(A,B,C);
    if(ans== INF) return 0;
    return ans;
}
