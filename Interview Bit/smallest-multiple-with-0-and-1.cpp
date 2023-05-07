/*
    name= Smallest Multiple With 0 and 1
    link- https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
    construct 2 arrays 
    one array stores characters 0/1  for every possible rem (between 0 , A-1 inclusive). 
    second array stores the parent of each remainder 

    construct bfs tree and make nodes of remainder , if in our tree any node with same remainder already exist at lower or equal level then don't add the new node because we want minimum answer.
    start bfs from rem= 1 and traverse until you reach rem= 0.   

    after reaching at 0 stop the bfs and start tracing the path from end(rem = 0) to start (rem=1) using the parent array and then finally reverse the array that will be the required minimum number. 
*/
string Solution::multiple(int A) {
    string s= "1";
    long long x=1;
    queue<pair<string,int>>q;
    q.push({s,x%A});
    set<int>rem;
    rem.insert(x);
    while(!q.empty()){
        string top= q.front().first;
        x= q.front().second;
        
        if(x == 0){
            return top;
        }
        q.pop();
        int left= (x*10)%A;
        int right= ((x*10) +1)%A;
        if(rem.find(left) == rem.end()){
            rem.insert(left);
            q.push({top+"0",left});
        }
        if(rem.find(right) == rem.end());{
            rem.insert(right);
            q.push({top+"1",right});
        }
    }
    return "";
}
